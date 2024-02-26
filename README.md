# Data Structure and Algorithm Project with Raspberry Pi 4 model B

## Installation

### (1) Raspberry Pi OS Setup

Ensure that the Raspberry Pi OS is installed and configured on Raspberry Pi 4. The latest version of the Raspberry Pi OS from the official Raspberry Pi website and follow the installation instructions provided.

### (2) Dependency Check

Verify that the Debian-based system on your Raspberry Pi has the following dependencies installed:
<ul>
  <li>make: A build automation tool used to compile and build software projects.</li>
  <li>cmake: A cross-platform build system generator used to control the software compilation process.</li>
  <li>gcc: The GNU Compiler Collection, which includes compilers for C, C++, and other programming languages.</li>
  <li>lighttpd: The Lightweight HTTP Server, which will be used to serve the frontend interface and facilitate communication with the backend.</li>
</ul>
You can install these dependencies using the package manager (apt-get) on Debian-based systems:
```
sudo apt-get update
sudo apt-get install make cmake gcc lighttpd
```

### (3) Project Setup
Clone the project repository containing the source code and necessary files to your Raspberry Pi:
```
git clone <project_repository_url>
```
Navigate to the project directory:
```
cd <project_directory>
```

### (4) Frontend Setup

Configure the lighttpd web server to serve the frontend interface. Ensure that the lighttpd.conf settings and flags are correctly configured to allow access to the frontend files.

Copy the frontend files (HTML, CSS, JavaScript) to the appropriate directory in the lighttpd web server root directory. This project is set up to be located at /var/www/dsaproject/html.
```
sudo cp -r DataStructure_and_Algorithm_Project/Frontend/* /var/www/dsaproject/html/
```
### (5) Backend Setup

Compile the main.cpp file, which contains the backend functionalities responsible for processing measurement data:

```
cmake CMakeLists.txt
make 
```

Copy the compiled executable file (DataStructAlg) to the CGI directory (cgi-bin) of the lighttpd web server:
```
sudo cp DataStructAlg /var/www/dsaproject/html/cgi-bin/
```
### (6) Configuration Check

Verify that the lighttpd.conf settings and flags are correctly configured to enable CGI execution and access to the backend executable. Ensure that the necessary permissions are set to allow execution of the CGI scripts.
```
sudo nano /etc/lighttpd/lighttpd.conf
```
Restart the lighttpd web server to apply the configuration changes:
```
sudo service lighttpd force-reload
```
Deploy project in web browser by typing in http://127.0.0.1:8008 to the address bar.

## User Interface 
![image](https://github.com/Gemmus/DataStructure_and_Algorithm_Project/assets/112064697/664b6b5b-83b1-4303-9629-7f48a86ae27a)
<br><small>_Figure 1: UI_</small><br> 

![image](https://github.com/Gemmus/DataStructure_and_Algorithm_Project/assets/112064697/4aac03be-ec2f-4ed8-916a-0df0f5f6569f)
<br><small>_Figure 2: Result of Measurement_</small><br> 
