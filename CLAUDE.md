# CLAUDE.md - AI Assistant Guide for FermLab

## Project Overview

FermLab is an **MQTT/Sparkplug B implementation** for Industrial IoT (IIoT) applications. It provides messaging infrastructure for industrial devices using the Sparkplug B specification, which standardizes MQTT topic structures and payload formats for industrial environments.

**License:** Eclipse Public License 2.0 (EPL-2.0)

### Target Hardware Platforms
- Motor Controllers
- ESP8266 microcontrollers
- Arduino Nano 33 IoT
- IIoT Host servers

## Repository Structure

```
FermLab/
├── FermLabJava/                    # Java server implementation
│   ├── pom.xml                     # Maven build configuration
│   └── src/main/java/io/github/labinho/
│       └── Main.java               # Entry point - Sparkplug B client
│
├── FermLabCpp/                     # Embedded C++ implementations
│   ├── ESP8266_PlatformIO/         # Active PlatformIO project
│   │   ├── platformio.ini          # PlatformIO configuration
│   │   ├── src/
│   │   │   └── main.cpp            # ESP8266 main application
│   │   ├── lib/
│   │   │   ├── connection/         # WiFi and MQTT connection library
│   │   │   ├── pubsubclient/       # MQTT client library
│   │   │   ├── sparkplug_b/        # Protocol buffer definitions
│   │   │   ├── tahu/               # Eclipse Tahu C library
│   │   │   └── nanopb/             # Lightweight protobuf library
│   │   ├── include/                # Header files
│   │   └── test/                   # Unit tests (not yet implemented)
│   │
│   └── ESP8266_Arduino/            # Legacy Arduino IDE project (reference only)
│
├── README.md                       # Project documentation
├── LICENCE                         # EPL-2.0 license
├── TechStack.png                   # Architecture diagram
└── .gitignore
```

## Technology Stack

### Java Component
- **Language:** Java 17
- **Build System:** Maven
- **Key Dependencies:**
  - Eclipse Tahu (v1.0.0) - Sparkplug B payload handling
  - Eclipse Paho - MQTT client (transitive via Tahu)
- **Main Class:** `io.github.labinho.Main`

### C++ Component (ESP8266)
- **Platform:** ESP8266 (esp12e board)
- **Build System:** PlatformIO
- **Framework:** Arduino
- **Key Libraries:**
  - PubSubClient - MQTT client
  - Nanopb - Protocol buffer encoding/decoding
  - Eclipse Tahu - Sparkplug B utilities

### Protocol
- **MQTT Namespace:** `spBv1.0`
- **Payload Format:** Sparkplug B (Protocol Buffers)

## Build Commands

### Java (FermLabJava/)
```bash
# Build the project (creates fat JAR)
cd FermLabJava && mvn package

# Clean and build
cd FermLabJava && mvn clean package

# Run the application
java -jar FermLabJava/target/FermLabJava-1.0-SNAPSHOT.jar
```

### C++ PlatformIO (FermLabCpp/ESP8266_PlatformIO/)
```bash
# Build
cd FermLabCpp/ESP8266_PlatformIO && pio run

# Upload to device
cd FermLabCpp/ESP8266_PlatformIO && pio run --target upload

# Serial monitor
cd FermLabCpp/ESP8266_PlatformIO && pio device monitor

# Clean
cd FermLabCpp/ESP8266_PlatformIO && pio run --target clean
```

## Code Conventions

### Naming Conventions
| Context | Convention | Example |
|---------|------------|---------|
| Java classes | PascalCase | `SparkplugBPayload` |
| Java methods | camelCase | `publishNodeBirth()` |
| Java packages | lowercase dots | `io.github.labinho` |
| C++ functions | snake_case | `setup_wifi()`, `mosq_callback()` |
| C++ files | snake_case | `setup_wifi.cpp` |
| Constants | UPPER_SNAKE_CASE | `USING_COMPRESSION` |
| Topics | lowercase/slashes | `esp8266/welcome` |

### Code Patterns

**Java - Sparkplug B Payload Creation:**
```java
SparkplugBPayload payload = new SparkplugBPayload(
    new Date(),           // timestamp
    new ArrayList<>(),    // metrics list
    getSeqNum(),          // sequence number (0-255)
    newUUID(),            // unique identifier
    null                  // body (optional)
);
payload.addMetric(new MetricBuilder("name", DataType, value).createMetric());
```

**C++ - MQTT Connection Pattern:**
```cpp
WiFiClient espClient;
PubSubClient mosq_client(espClient);

void setup() {
    setup_wifi(wifi_ssid, wifi_password);
    mosq_client.setServer(mosq_server, mosq_port);
    mosq_client.setCallback(mosq_callback);
    // Connect with MAC-based client ID
}
```

### Important Files

| File | Purpose |
|------|---------|
| `FermLabJava/src/main/java/io/github/labinho/Main.java` | Java Sparkplug B client entry point |
| `FermLabCpp/ESP8266_PlatformIO/src/main.cpp` | ESP8266 main application |
| `FermLabCpp/ESP8266_PlatformIO/lib/connection/connection.h` | Connection library header |
| `FermLabCpp/ESP8266_PlatformIO/lib/sparkplug_b/sparkplug_b.proto` | Protocol buffer definitions |
| `credentials.h` | WiFi/MQTT credentials (git-ignored, must create locally) |

## Configuration

### Credentials Setup (ESP8266)
Create a `credentials.h` file in the include directory (this file is git-ignored):

```cpp
// FermLabCpp/ESP8266_PlatformIO/include/credentials.h
const char* wifi_ssid = "YOUR_WIFI_SSID";
const char* wifi_password = "YOUR_WIFI_PASSWORD";
const char* mosq_server = "YOUR_MQTT_BROKER_IP";
const int mosq_port = 1883;
const char* mosq_username = "YOUR_USERNAME";
const char* mosq_password = "YOUR_PASSWORD";
```

### Java MQTT Configuration
Currently hardcoded in `Main.java`:
```java
private String serverUrl = "tcp://localhost:1883";
private String edgeNode = "FermLabJava Sparkplug B Example";
private String groupId = "Sparkplug B Devices";
private String clientId = "SparkplugBExampleEdgeNode";
```

## Development Status

This project is in **early development**. Key incomplete features:

### Java (Main.java)
- [ ] `publishDeviceBirth()` - Not implemented
- [ ] Publisher execution is commented out
- [ ] MQTT connection/callback handling incomplete
- TODO comments indicate learning-in-progress codebase

### C++ (main.cpp)
- [ ] Sparkplug B birth certificates not implemented
- [ ] Protocol buffer encoding not yet integrated (imports commented out)
- [ ] Basic LED blink and MQTT pub/sub working as example

### Testing
- Test infrastructure exists (`test/` directory) but no tests implemented
- PlatformIO unit testing framework ready to use

## Key Technical Notes

### Sparkplug B Protocol
- Namespace: `spBv1.0`
- Topic format: `spBv1.0/{group_id}/{message_type}/{edge_node_id}[/{device_id}]`
- Message types: NBIRTH, NDEATH, DBIRTH, DDEATH, NDATA, DDATA, NCMD, DCMD, STATE
- Sequence numbers: 0-255, wrap around

### Memory Management (C++)
- Tahu library includes `free_payload()` for cleanup
- Shallow copy semantics in protobuf structures - be careful with memory ownership

### Serial Debugging
- ESP8266 uses Serial at 9600 baud
- Use `Serial.print()` / `Serial.printf()` for debugging

## Git Ignored Files
- `*credentials.h` - Sensitive WiFi/MQTT credentials
- `*/target/` - Maven build outputs
- `*/.idea/` - IDE configuration
- `.DS_Store` - macOS system files

## Common Tasks for AI Assistants

### When implementing Sparkplug B features:
1. Follow the Eclipse Tahu patterns in existing code
2. Use the `spBv1.0` namespace
3. Implement birth/death certificate publishing
4. Handle sequence numbers correctly (0-255 wrap)

### When working with ESP8266:
1. Ensure `credentials.h` exists before building
2. Use the connection library functions for WiFi/MQTT setup
3. Keep memory usage minimal - ESP8266 has limited RAM
4. Test MQTT connectivity before implementing Sparkplug B features

### When modifying build configuration:
- Java: Edit `FermLabJava/pom.xml`
- C++: Edit `FermLabCpp/ESP8266_PlatformIO/platformio.ini`

## External Resources
- [Sparkplug B Specification](https://sparkplug.eclipse.org/)
- [Eclipse Tahu](https://github.com/eclipse/tahu) - Sparkplug B reference implementation
- [PlatformIO Documentation](https://docs.platformio.org/)
- [PubSubClient Library](https://pubsubclient.knolleary.net/)
- [Nanopb Documentation](https://jpa.kapsi.fi/nanopb/)
