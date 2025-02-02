# Baekjoon

<br/>
<br/>

## Environment

-   Browser: Arc Browser (Chromium)
-   ChromeDriver: 132.0.6834.160
-   Python: 3.11.4
-   Selenium: 4.27.1
-   OS: macOS Sequoia 15.1

<br/>
<br/>

## Getting started

### Browser and ChromeDriver Version

Ensure that the version of ChromeDriver matches the version of the Chromium-based browser you are using. This is crucial for compatibility and to avoid any unexpected issues.

<br/>

### setup_arc.sh

Make sure to update the browser path in the [setup_arc.sh](util/setup_arc.sh) script to match the location of your Arc Browser installation and ensure that the port specified for remote debugging is not in use by another application. The default port used in the script is `9222`. This is necessary for the script to correctly launch the browser.

Example:

```bash
#!/bin/bash

# Update this path to the location of your Arc Browser installation
BROWSER_PATH="/Applications/Arc.app/Contents/MacOS/Arc"
PORT=9222

# Launch the browser with remote debugging enabled on port 9222
"$BROWSER_PATH" --remote-debugging-port=$PORT
```

<br/>

### .env

Create a `.env` file in the root directory of the project. You can use the `.env.example` file as a reference. The `.env` file should contain your user ID and password, and the path to your ChromeDriver executable.

Example:

```plaintext
USER_ID=your_user_id
PASSWORD=your_password
CHROMEDRIVER_PATH=/path/to/chromedriver
```

Replace `your_user_id`, `your_password`, and `/path/to/chromedriver` with your actual Baekjoon user ID and password, and the path to your ChromeDriver executable.

<br/>
<br/>

## Usage

### build

To build the project, run the following command:

```bash
make build <problem_number>
```

<br/>

### submit

To submit a solution to a problem, run the following command:

```bash
make submit <problem_number>
```

<br/>

### clean

To clean all executables, run the following command:

```bash
make clean
```

<br/>
<br/>

## License

This repository is licensed under the MIT License. See [LICENSE](LICENSE.md) for more information.

<br/>
<br/>

## Contact

You can contact me at <mailto:younganswer@kookmin.ac.kr>
