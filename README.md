<h1 align="center">
	<img src="https://static.thenounproject.com/png/2325457-200.png" width="150px"><br>
    trail - A small, minimal HTTP library written in C.
</h1>
<p align="center">
    trail is a small, minimal, and easy-to-use HTTP library written in C that supports GET and POST requests.
</p>

<p align="center">
	<a href="https://deno.land" target="_blank">
    	<img src="https://img.shields.io/badge/Version-1.0.0-7DCDE3?style=for-the-badge" alt="Version">
</p>

## Features
Features |
-------- |
Sending GET requests
Sending POST requests

## Information
- How to use functions:
  * Sending GET request ```requests_get(int port, char *website, char *directory);``` Parameters: (port, website, directory)
  * Sending POST request ```requests_post(int port, char *website, char *directory, char *post_data);``` Parameters: (port, website, directory, data)

## Setup & Installation
```
Steps for compiling & running:
  install.sh
  gcc -o <binary> <source_file> trail.so
```

## Credits
```
https://github.com/0x1CA3
```

### Contributions 🎉
###### All contributions are accepted, simply open an Issue / Pull request.
