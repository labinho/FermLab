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
    private int seq = 0;
    // TODO: Find out what seqLock is doing.
    private Object seqLock = new Object();
    private String serverUrl = "tcp://localhost:1883";
    private String clientId = "SparkplugBExampleEdgeNode";
    private MqttClient client;

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
                System.out.println(payload);
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
}