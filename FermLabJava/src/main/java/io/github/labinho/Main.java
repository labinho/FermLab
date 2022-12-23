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
// TODO: "public STATIC class Main {}" benötigt Implementierung von MqttCallbackExtended

    private int seq = 0;
    private Object seqLock = new Object();
    private String serverUrl = "tcp://localhost:1883";
    private String clientId = "SparkplugBExampleEdgeNode";
    private MqttClient client;

    public void run() {
        System.out.println("Hello FermLabJava");

        try {
            System.out.println("Create client");
            client = new MqttClient(serverUrl, clientId);
            client.setTimeToWait(2000);
            publishBirth();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static void main(String[] args) {
        System.out.println("Create new Main()");
        Main example = new Main();
        example.run();
    }
    private void publishBirth() {
        publishNodeBirth();
        publishDeviceBirth();
    }

    private void publishNodeBirth() {
        System.out.println("publish Node Birth");
        try {
            synchronized (seqLock) {
                // Reset the sequence number
                seq = 0;
                // Create the BIRTH payload and set the position and other metrics
                SparkplugBPayload payload =
                        new SparkplugBPayload(new Date(), new ArrayList<>(), getSeqNum(), newUUID(), null);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private long getSeqNum() throws Exception {
        System.out.println("seq: " + seq);
        if (seq == 256) {
            seq = 0;
        }
        return seq++;
    }

    private String newUUID() {
        return java.util.UUID.randomUUID().toString();
    }

    private void publishDeviceBirth() {
        System.out.println("publish Device Birth");
    }
}