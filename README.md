# RoomGuard Sentinel

RoomGuard Sentinel is an Arduino-based room entry detection and alert system designed to enhance security and monitoring. The system detects when someone enters a room, logs the event to a Linux server, stores the data in an SQL database, and sends an alert via text message to the designated user. Additionally, RoomGuard Sentinel provides a web interface where users can access and manage their alarms.

## Features

- **Real-time Entry Detection**: Utilizes sensors to detect when someone enters the room.
- **Data Logging**: Sends entry data to a Linux server for storage in an SQL database.
- **Instant Alerts**: Sends text message alerts to users when an entry is detected.
- **Web Interface**: Allows users to access and manage their alarms through a user-friendly website.
- **Open Source**: Fully customizable and extendable to fit specific needs.

## Components

- **Arduino Device**: Equipped with entry detection sensors.
- **Linux Server**: Handles data storage and processing.
- **SQL Database**: Stores entry logs and user information.
- **SMS Gateway**: Sends text message alerts to users.
- **Web Interface**: Provides access to alarm data and settings.

## Installation

### Arduino Setup

1. Connect the entry detection sensors to the Arduino.
2. Upload the provided Arduino code to the device.

### Server Setup

1. Set up a Linux server with an SQL database.
2. Deploy the server-side scripts to handle data logging and alerting.

### Web Interface

1. Deploy the web application to a server.
2. Configure the web app to connect to your SQL database.

### SMS Alerts

1. Set up an SMS gateway or use an existing service to send text messages.
2. Configure the server scripts to use the SMS service for alerts.

## Usage

1. Deploy the Arduino device in the room you wish to monitor.
2. Start the server to begin logging data and monitoring entries.
3. Access the web interface to view logs, manage settings, and configure alerts.
4. Receive text message alerts whenever an entry is detected.
