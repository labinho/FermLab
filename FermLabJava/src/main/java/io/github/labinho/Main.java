package io.github.labinho;

import static org.eclipse.tahu.message.model.MetricDataType.Boolean;
import static org.eclipse.tahu.message.model.MetricDataType.DataSet;
import static org.eclipse.tahu.message.model.MetricDataType.DateTime;
import static org.eclipse.tahu.message.model.MetricDataType.Double;
import static org.eclipse.tahu.message.model.MetricDataType.Float;
import static org.eclipse.tahu.message.model.MetricDataType.Int16;
import static org.eclipse.tahu.message.model.MetricDataType.Int32;
import static org.eclipse.tahu.message.model.MetricDataType.Int64;
import static org.eclipse.tahu.message.model.MetricDataType.Int8;
import static org.eclipse.tahu.message.model.MetricDataType.String;
import static org.eclipse.tahu.message.model.MetricDataType.Template;
import static org.eclipse.tahu.message.model.MetricDataType.Text;
import static org.eclipse.tahu.message.model.MetricDataType.UInt16;
import static org.eclipse.tahu.message.model.MetricDataType.UInt32;
import static org.eclipse.tahu.message.model.MetricDataType.UInt64;
import static org.eclipse.tahu.message.model.MetricDataType.UInt8;
import static org.eclipse.tahu.message.model.MetricDataType.UUID;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadLocalRandom;

import javax.net.SocketFactory;
import javax.net.ssl.SSLSocketFactory;

import org.eclipse.paho.client.mqttv3.IMqttDeliveryToken;
import org.eclipse.paho.client.mqttv3.MqttCallbackExtended;
import org.eclipse.paho.client.mqttv3.MqttClient;
import org.eclipse.paho.client.mqttv3.MqttConnectOptions;
import org.eclipse.paho.client.mqttv3.MqttException;
import org.eclipse.paho.client.mqttv3.MqttMessage;
import org.eclipse.paho.client.mqttv3.MqttPersistenceException;
import org.eclipse.tahu.message.SparkplugBPayloadDecoder;
import org.eclipse.tahu.message.SparkplugBPayloadEncoder;
import org.eclipse.tahu.message.model.DataSet;
import org.eclipse.tahu.message.model.DataSet.DataSetBuilder;
import org.eclipse.tahu.message.model.DataSetDataType;
import org.eclipse.tahu.message.model.Metric;
import org.eclipse.tahu.message.model.Metric.MetricBuilder;
import org.eclipse.tahu.message.model.Parameter;
import org.eclipse.tahu.message.model.ParameterDataType;
import org.eclipse.tahu.message.model.PropertyDataType;
import org.eclipse.tahu.message.model.PropertySet;
import org.eclipse.tahu.message.model.PropertySet.PropertySetBuilder;
import org.eclipse.tahu.message.model.PropertyValue;
import org.eclipse.tahu.message.model.Row.RowBuilder;
import org.eclipse.tahu.message.model.SparkplugBPayload;
import org.eclipse.tahu.message.model.SparkplugBPayload.SparkplugBPayloadBuilder;
import org.eclipse.tahu.message.model.Template;
import org.eclipse.tahu.message.model.Template.TemplateBuilder;
import org.eclipse.tahu.message.model.Value;
import org.eclipse.tahu.util.CompressionAlgorithm;
import org.eclipse.tahu.util.PayloadUtil;

public class Main {
    private static final boolean USING_COMPRESSION = false;
    private static final CompressionAlgorithm compressionAlgorithm = CompressionAlgorithm.GZIP;
    private static final String NAMESPACE = "spBv1.0";
    private int seq = 0;
    private int bdSeq = 0;
    // TODO: Find out what seqLock is doing.
    private Object seqLock = new Object();
    private String serverUrl = "tcp://localhost:1883";
    private String edgeNode = "FermLabJava Sparkplug B Example";
    private String groupId = "Sparkplug B Devices";
    private String clientId = "SparkplugBExampleEdgeNode";
    private MqttClient client;
    private ExecutorService executor;

    public void run() {
        try {
            // TODO: What are attributes and methods of MqttClient? Find out what is available after declaration.
            client = new MqttClient(serverUrl, clientId);
            client.setTimeToWait(2000);
            publishBirth();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static void main(String[] args) {
        System.out.println("Hello FermLabJava");
        Main example = new Main();
        example.run();
    }
    private void publishBirth() {
        publishNodeBirth();
        publishDeviceBirth();
    }
    private void publishNodeBirth() {
        System.out.println("publishNodeBirth()");
        try {
            // TODO: What does 'synchronized' mean? Find out what 'synchronized (seqLock) {}' is doing.
            synchronized (seqLock) {
                // seq = 0;
                // TODO: What is the structure of 'payload'? Find out how to access and populate 'ArrayList'.
                SparkplugBPayload payload = new SparkplugBPayload(new Date(), new ArrayList<>(), getSeqNum(), newUUID(), null);
                payload.addMetric(new MetricBuilder("bdSeq", Int64, (long) bdSeq).createMetric());
                payload.addMetric(new MetricBuilder("Node Control/Rebirth", Boolean, false).createMetric());
                PropertySet nestedPropertySet = new PropertySetBuilder()
                        .addProperty("custom", new PropertyValue(PropertyDataType.String, "Custom Value"))
                        .createPropertySet();
                PropertySet propertySet = new PropertySetBuilder()
                        .addProperty("engUnit", new PropertyValue(PropertyDataType.String, "My Units"))
                        .addProperty("engLow", new PropertyValue(PropertyDataType.Double, 1.0))
                        .addProperty("engHigh", new PropertyValue(PropertyDataType.Double, 10.0))
                        .addProperty("Custom nested node prop", new PropertyValue(PropertyDataType.PropertySet, nestedPropertySet))
                        /*
                         * .addProperty("CustA", new PropertyValue(PropertyDataType.String, "Custom A"))
                         * .addProperty("CustB", new PropertyValue(PropertyDataType.Double, 10.0)) .addProperty("CustC",
                         * new PropertyValue(PropertyDataType.Int32, 100))
                         */
                        .createPropertySet();
                payload.addMetric(
                        new MetricBuilder("MyMetric", String, "My Value").properties(propertySet).createMetric());
                System.out.println("Publishing Edge Node Birth");
                System.out.println(payload);
                //executor.execute(new Publisher(NAMESPACE + "/" + groupId + "/NBIRTH/" + edgeNode, payload));
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    private void publishDeviceBirth() {
    }
    private long getSeqNum() throws Exception {
        if (seq == 256) {
            seq = 0;
        }
        return seq++;
    }
    private String newUUID() {
        return java.util.UUID.randomUUID().toString();
    }
    private class Publisher implements Runnable {

        private String topic;
        private SparkplugBPayload outboundPayload;

        public Publisher(String topic, SparkplugBPayload outboundPayload) {
            this.topic = topic;
            this.outboundPayload = outboundPayload;
        }

        // TODO: what is the difference between this "run()" and in line 79?
        public void run() {
            try {
                outboundPayload.setTimestamp(new Date());
                SparkplugBPayloadEncoder encoder = new SparkplugBPayloadEncoder();

                // Compress payload (optional)
                if (USING_COMPRESSION) {
                    client.publish(topic,
                            encoder.getBytes(PayloadUtil.compress(outboundPayload, compressionAlgorithm, false), false),
                            0, false);
                } else {
                    client.publish(topic, encoder.getBytes(outboundPayload, false), 0, false);
                }
            } catch (MqttPersistenceException e) {
                e.printStackTrace();
            } catch (MqttException e) {
                e.printStackTrace();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}