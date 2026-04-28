# Databases

This directory contains database configurations and Docker Compose files for local development environments.

## Topics

### Topic 1: Overview

This folder provides pre-configured database setups to help you quickly spin up database environments for testing and development purposes without complicated setup procedures.

### Topic 2: Prerequisites

Before using any of the Docker Compose files in this directory, ensure you have:

- **Docker** installed on your system
- **Docker Compose** installed (comes with Docker Desktop)
- Sufficient disk space for database volumes
- Port availability (verify ports aren't already in use)

### Topic 3: Available Databases

The following database services are available:

- **PostgreSQL (Playground)** - Lightweight PostgreSQL setup for development and testing (Port 65001)
- **MongoDB (Playground)** - NoSQL document database setup for development and testing (Port 65002)
- **Redis (Playground)** - In-memory data store and cache setup for development and testing (Port 65003)

### Topic 4: General Docker Compose Commands

Common commands for managing database services:

```bash
# Start services
docker-compose -f <compose-file> up -d

# Stop services
docker-compose -f <compose-file> down

# View logs
docker-compose -f <compose-file> logs -f

# Connect to container
docker-compose -f <compose-file> exec <service-name> bash

# Remove volumes (WARNING: deletes data)
docker-compose -f <compose-file> down -v
```

### Topic 5: Database Connection Details Format

When connecting to any database service, you'll need:

- **Host**: `localhost` (for services running locally)
- **Port**: Specified in the compose file (mapped port)
- **Username**: Specified in environment variables
- **Password**: Specified in environment variables
- **Database**: Default database name specified in environment variables

### Topic 6: Database Management Tools

For GUI-based database management and query execution:

- **DBeaver Community Edition** (Free)
  - Download: [https://dbeaver.io/download/](https://dbeaver.io/download/)
  - Supports multiple database systems including PostgreSQL
  - Features: SQL editor, data visualization, database migration tools
  - Works on Windows, macOS, and Linux

---

## Topic 7: Playground PostgreSQL Compose

### Overview

The `playground-postgresql.yml` file provides a lightweight PostgreSQL database environment designed for development, testing, and experimentation. This setup allows you to quickly spin up an isolated PostgreSQL instance without affecting your system or other projects.

### What Happens with Playground PostgreSQL Compose

When you start the playground PostgreSQL compose file:

1. **Container Creation**: Docker creates a new PostgreSQL container named `playground_postgresql`
2. **Database Initialization**: A new PostgreSQL database instance is initialized with default credentials
3. **Port Mapping**: PostgreSQL service becomes accessible on `localhost:65001`
4. **Volume Creation**: A Docker volume named `pg_data` is created to persist database data between container restarts
5. **Resource Allocation**: The container is limited to 512MB memory and 0.5 CPU cores to prevent resource exhaustion

### Service Configuration

| Parameter | Value | Description |
|-----------|-------|-------------|
| **Image** | `postgres:latest` | Official PostgreSQL latest image |
| **Container Name** | `playground_postgresql` | Friendly identifier for the container |
| **Username** | `playground` | PostgreSQL superuser username |
| **Password** | `playground` | PostgreSQL superuser password |
| **Database** | `playground` | Default database created on startup |
| **Host Port** | `65001` | Local machine port to access PostgreSQL |
| **Container Port** | `5432` | PostgreSQL's internal port |
| **Memory Limit** | `512MB` | Maximum memory allocation |
| **CPU Limit** | `0.5` | Maximum CPU cores (half a core) |
| **Storage Limit** | `2GB` | Maximum volume size |

### How to Use

#### Step 1: Start the PostgreSQL Service

Open your terminal and navigate to the databases directory:

```bash
cd databases
```

Start the PostgreSQL service:

```bash
docker-compose -f playground-postgresql.yml up -d
```

Expected output:
```
Creating volume "databases_pg_data" ...
Creating playground_postgresql ... done
```

#### Step 2: Verify the Service is Running

Check if the container is running:

```bash
docker-compose -f playground-postgresql.yml ps
```

You should see:
```
NAME                   COMMAND                  SERVICE        STATUS      PORTS
playground_postgresql  "docker-entrypoint…"     pg-playground  Up ...      0.0.0.0:65001->5432/tcp
```

#### Step 3: Connect Using Terminal (psql)

To connect directly from the terminal:

```bash
# Connect as the playground user
docker-compose -f playground-postgresql.yml exec pg-playground psql -U playground -d playground
```

Once connected, you can run SQL commands:

```sql
-- View connected databases
\l

-- View tables
\dt

-- Exit psql
\q
```

#### Step 4: Connect Using DBeaver GUI (Recommended)

For a visual interface, use DBeaver:

1. **Download DBeaver**: Visit [https://dbeaver.io/download/](https://dbeaver.io/download/)
   - Select your operating system (Windows, macOS, or Linux)
   - Choose the "Community Edition" (free)
   - Install the application

2. **Create a New Database Connection**:
   - Open DBeaver
   - Click `Database` → `New Database Connection`
   - Select `PostgreSQL` from the list
   - Click `Next`

3. **Enter Connection Details**:
   - **Server Host**: `localhost`
   - **Port**: `65001`
   - **Database**: `playground`
   - **Username**: `playground`
   - **Password**: `playground`
   - Leave other fields as defaults
   - Click `Test Connection` to verify

4. **Browse and Manage Data**:
   - Double-click the connection to open it
   - Browse schemas, tables, and data
   - Execute SQL queries using the SQL Editor (Ctrl+Enter to run)
   - Perform backups and migrations

### Common Terminal Commands

```bash
# Start the service (run from databases directory)
docker-compose -f playground-postgresql.yml up -d

# Stop the service
docker-compose -f playground-postgresql.yml down

# View logs in real-time
docker-compose -f playground-postgresql.yml logs -f pg-playground

# Connect to PostgreSQL terminal
docker-compose -f playground-postgresql.yml exec pg-playground psql -U playground -d playground

# Create a new database
docker-compose -f playground-postgresql.yml exec pg-playground createdb -U playground test_db

# Backup the database
docker-compose -f playground-postgresql.yml exec pg-playground pg_dump -U playground playground > backup.sql

# Restore from backup
cat backup.sql | docker-compose -f playground-postgresql.yml exec -T pg-playground psql -U playground -d playground

# Remove service and delete all data (WARNING: Permanent)
docker-compose -f playground-postgresql.yml down -v

# View container resource usage
docker stats playground_postgresql
```

### Quick Reference - Connection Strings

**psql CLI**:
```bash
psql -h localhost -p 65001 -U playground -d playground
```

**Python (psycopg2)**:
```python
import psycopg2
conn = psycopg2.connect(
    host="localhost",
    port=65001,
    user="playground",
    password="playground",
    database="playground"
)
```

**Node.js (pg)**:
```javascript
const { Client } = require('pg');
const client = new Client({
  host: 'localhost',
  port: 65001,
  user: 'playground',
  password: 'playground',
  database: 'playground',
});
```

**JDBC (Java)**:
```
jdbc:postgresql://localhost:65001/playground?user=playground&password=playground
```

### Troubleshooting

| Issue | Solution |
|-------|----------|
| **Port 65001 already in use** | Change the port mapping in the compose file or stop the conflicting service |
| **Cannot connect with DBeaver** | Verify the service is running with `docker-compose ps` and check the port mapping |
| **Permission denied errors** | Ensure Docker daemon is running and you have proper permissions |
| **Out of memory** | Increase the memory limit in the compose file under `deploy.resources.limits.memory` |
| **Data not persisting** | Ensure the volume is not being removed; don't use `docker-compose down -v` |

### Cleanup and Removal

When you're done with the playground environment:

```bash
# Stop the service (preserves data)
docker-compose -f playground-postgresql.yml down

# Stop and remove all data (WARNING: cannot be recovered)
docker-compose -f playground-postgresql.yml down -v
```

---

## Topic 8: Playground MongoDB Compose

### Overview

The `playground-mongodb.yml` file provides a lightweight MongoDB database environment designed for NoSQL development, testing, and experimentation. MongoDB is a document-oriented database that stores data in JSON-like format, making it ideal for flexible schema applications.

### What Happens with Playground MongoDB Compose

When you start the playground MongoDB compose file:

1. **Container Creation**: Docker creates a new MongoDB container named `playground_mongodb`
2. **Authentication Setup**: MongoDB is configured with root credentials for access control
3. **Port Mapping**: MongoDB service becomes accessible on `localhost:65002`
4. **Volume Creation**: A Docker volume named `mongo_data` is created to persist database data
5. **Resource Allocation**: The container is limited to 512MB memory and 0.5 CPU cores

### Service Configuration

| Parameter | Value | Description |
|-----------|-------|-------------|
| **Image** | `mongo:latest` | Official MongoDB latest image |
| **Container Name** | `playground_mongodb` | Friendly identifier for the container |
| **Username** | `playground` | MongoDB root username |
| **Password** | `playground` | MongoDB root password |
| **Database** | `playground` | Default database created on startup |
| **Host Port** | `65002` | Local machine port to access MongoDB |
| **Container Port** | `27017` | MongoDB's internal port |
| **Memory Limit** | `512MB` | Maximum memory allocation |
| **CPU Limit** | `0.5` | Maximum CPU cores |
| **Storage Limit** | `2GB` | Maximum volume size |

### How to Use

#### Step 1: Start the MongoDB Service

```bash
cd databases
docker-compose -f playground-mongodb.yml up -d
```

#### Step 2: Verify the Service is Running

```bash
docker-compose -f playground-mongodb.yml ps
```

#### Step 3: Connect Using MongoDB Shell (mongosh)

```bash
docker-compose -f playground-mongodb.yml exec mongo-playground mongosh -u playground -p playground --authenticationDatabase admin
```

Once connected, run MongoDB commands:

```javascript
// Show all databases
show databases

// Switch to playground database
use playground

// Show collections
show collections

// Insert a document
db.test.insertOne({ name: "John", age: 30 })

// Find documents
db.test.find()

// Exit
exit
```

#### Step 4: Connect Using DBeaver GUI

1. Open DBeaver and click `Database` → `New Database Connection`
2. Select `MongoDB` from the list
3. Enter connection details:
   - **Server Host**: `localhost`
   - **Port**: `65002`
   - **Username**: `playground`
   - **Password**: `playground`
   - **Authentication Database**: `admin`
4. Click `Test Connection` and then `Finish`
5. Browse collections and execute queries

### Common Terminal Commands

```bash
# Start the service
docker-compose -f playground-mongodb.yml up -d

# Stop the service
docker-compose -f playground-mongodb.yml down

# View logs
docker-compose -f playground-mongodb.yml logs -f mongo-playground

# Connect to MongoDB shell
docker-compose -f playground-mongodb.yml exec mongo-playground mongosh -u playground -p playground --authenticationDatabase admin

# Create a backup
docker-compose -f playground-mongodb.yml exec mongo-playground mongodump -u playground -p playground --authenticationDatabase admin --out /data/db/backup

# Restore from backup
docker-compose -f playground-mongodb.yml exec mongo-playground mongorestore -u playground -p playground --authenticationDatabase admin /data/db/backup
```

### Quick Reference - Connection Strings

**MongoDB Shell**:
```bash
mongosh "mongodb://playground:playground@localhost:65002/?authSource=admin"
```

**Python (pymongo)**:
```python
from pymongo import MongoClient
client = MongoClient('mongodb://playground:playground@localhost:65002/?authSource=admin')
db = client['playground']
```

**Node.js (mongodb)**:
```javascript
const MongoClient = require('mongodb').MongoClient;
const uri = "mongodb://playground:playground@localhost:65002/?authSource=admin";
const client = new MongoClient(uri);
```

**Java**:
```
mongodbconnectionstring://playground:playground@localhost:65002/?authSource=admin
```

---

## Topic 9: Playground Redis Compose

### Overview

The `playground-redis.yml` file provides a lightweight Redis environment designed for caching, session management, and real-time data applications. Redis is an in-memory data structure store that excels at high-speed read/write operations.

### What Happens with Playground Redis Compose

When you start the playground Redis compose file:

1. **Container Creation**: Docker creates a new Redis container named `playground_redis`
2. **Password Protection**: Redis is configured with password authentication
3. **Port Mapping**: Redis service becomes accessible on `localhost:65003`
4. **Volume Creation**: A Docker volume named `redis_data` is created to persist data
5. **Resource Allocation**: The container is limited to 256MB memory and 0.5 CPU cores

### Service Configuration

| Parameter | Value | Description |
|-----------|-------|-------------|
| **Image** | `redis:latest` | Official Redis latest image |
| **Container Name** | `playground_redis` | Friendly identifier for the container |
| **Password** | `playground` | Redis authentication password |
| **Host Port** | `65003` | Local machine port to access Redis |
| **Container Port** | `6379` | Redis's internal port |
| **Memory Limit** | `256MB` | Maximum memory allocation |
| **CPU Limit** | `0.5` | Maximum CPU cores |
| **Storage Limit** | `1GB` | Maximum volume size |

### How to Use

#### Step 1: Start the Redis Service

```bash
cd databases
docker-compose -f playground-redis.yml up -d
```

#### Step 2: Verify the Service is Running

```bash
docker-compose -f playground-redis.yml ps
```

#### Step 3: Connect Using redis-cli

```bash
docker-compose -f playground-redis.yml exec redis-playground redis-cli -a playground
```

Once connected, run Redis commands:

```bash
# Set a key
SET mykey "Hello Redis"

# Get a key
GET mykey

# Set with expiration (30 seconds)
SETEX tempkey 30 "This will expire"

# Get all keys
KEYS *

# Check key expiration
TTL mykey

# Delete a key
DEL mykey

# Flush all data (WARNING: Deletes everything)
FLUSHALL

# Exit
exit
```

#### Step 4: Connect Using GUI Tools

**Using RedisInsight** (Official Redis GUI):
- Download from: [https://redis.com/redis-enterprise/redis-insight/](https://redis.com/redis-enterprise/redis-insight/)
- Connection Details:
  - **Host**: `localhost`
  - **Port**: `65003`
  - **Default Database**: `0`
  - **ACL Username**: Leave empty (uses default)
  - **ACL Password**: `playground`

**Using DBeaver**:
- Supports Redis connections (requires Redis extension in DBeaver)
- Same host and port configuration as cli

### Common Terminal Commands

```bash
# Start the service
docker-compose -f playground-redis.yml up -d

# Stop the service
docker-compose -f playground-redis.yml down

# View logs
docker-compose -f playground-redis.yml logs -f redis-playground

# Connect to redis-cli
docker-compose -f playground-redis.yml exec redis-playground redis-cli -a playground

# View all keys
docker-compose -f playground-redis.yml exec redis-playground redis-cli -a playground KEYS "*"

# Get server info
docker-compose -f playground-redis.yml exec redis-playground redis-cli -a playground INFO

# Monitor real-time commands
docker-compose -f playground-redis.yml exec redis-playground redis-cli -a playground MONITOR

# Create a backup
docker-compose -f playground-redis.yml exec redis-playground redis-cli -a playground SAVE

# Check memory usage
docker-compose -f playground-redis.yml exec redis-playground redis-cli -a playground INFO memory
```

### Quick Reference - Connection Strings

**redis-cli**:
```bash
redis-cli -h localhost -p 65003 -a playground
```

**Python (redis)**:
```python
import redis
r = redis.Redis(host='localhost', port=65003, password='playground', decode_responses=True)
r.set('key', 'value')
print(r.get('key'))
```

**Node.js (redis)**:
```javascript
const redis = require('redis');
const client = redis.createClient({
  host: 'localhost',
  port: 65003,
  password: 'playground'
});
```

**Java (Jedis)**:
```
Jedis jedis = new Jedis("localhost", 65003);
jedis.auth("playground");
```

### Troubleshooting

| Issue | Solution |
|-------|----------|
| **Port 65003 already in use** | Change the port mapping in compose file or stop conflicting service |
| **Authentication failed** | Verify password is correct: `playground` |
| **Memory limit exceeded** | Increase memory limit in compose file or use Redis eviction policies |
| **Cannot connect** | Ensure service is running with `docker-compose ps` |
| **Data not persisting** | Ensure volume is not removed; avoid `docker-compose down -v` |

---

## Additional Resources

- [PostgreSQL Official Documentation](https://www.postgresql.org/docs/)
- [MongoDB Official Documentation](https://docs.mongodb.com/)
- [Redis Official Documentation](https://redis.io/documentation)
- [Docker Compose Documentation](https://docs.docker.com/compose/)
- [DBeaver Documentation](https://dbeaver.io/docs/)
- [RedisInsight Download](https://redis.com/redis-enterprise/redis-insight/)
- [psql Command Reference](https://www.postgresql.org/docs/current/app-psql.html)
