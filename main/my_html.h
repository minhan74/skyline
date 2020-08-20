/**
 * @brief HTML & CSS contents which display on the web server
 */
#define HTML_RESPONSE "<html> \
    <head> \
        <title>C&#7917;a Gi&#7871;ng Tr&#7901;i</title> \
        <meta name=\"viewport\" content=\"width=device-width; initial-scale=1.0; maximum-scale=1.0; user-scalable=0;\"/> \
        <style> \
        * { font-family: Arial; } \
        #btn { \
            color: white; \
            width:33vw; \
            height: 20vh; \
            background-color: #33c930; \
            font-size: 200%; \
            position: absolute; \
            top: 50%; \
            left: 50%; \
            transform: translate(-50%,-50%); \
            border-radius: 10px; \
            border: 0; \
            outline: 0; \
            transition: .05s; \
            font-weight: bold;      \
        } \
        #btn:active { \
            background-color: brown; \
            font-size: 180%; \
            width: 32vw; \
            height: 19vh; \
        } \
        #btn.close { background-color: #db2323;} \
        #btn.closing {background-color: #9c0b0b;} \
        #btn.opening {background-color: #0c8c0a;} \
        body { background-color: #fff;} \
        #header { \
            margin-top: 7%; \
            text-align: center; \
            font-size: 360%; \
        } \
 \
        #footer { \
            position: absolute; \
            bottom: 3%; \
            left: 50%; \
            text-align: center; \
            transform: translate(-50%, 0); \
            font-size: 80%; \
            cursor: pointer; \
        } \
 \
        #footer:hover { \
            color: orange; \
        } \
 \
        #credit-pannel { \
            position: fixed; \
            top: 150%; \
            bottom: 200%; \
            left: 0; \
            right: 0; \
            transition: .4s; \
            background-color: lightgrey; \
        } \
 \
        #credit-pannel.show { \
            top: 0; \
            bottom: 0; \
        } \
 \
        #credit-header { \
            text-align: center; \
            background-color: white; \
            padding: 20px; \
            margin-top: 0; \
            border: 1px solid black; \
        } \
 \
        #credit-content { \
            background-color: white; \
            padding: 20px; \
            border: 1px solid black; \
            font-size: 110%; \
        } \
 \
        #credit-btn { \
            border: 0; \
            outline: 0; \
            border-radius: 5px; \
            padding: 10px 40px; \
            margin-top: 20px; \
            position: relative; \
            left: 50%; \
            transform: translate(-50%, 0); \
            font-size: 120%; \
        } \
 \
        #credit-btn:hover { \
            background-color: rgb(0, 0, 0, 0.3); \
        } \
 \
        #credit-btn:active { \
            background-color: grey; \
        } \
    </style> \
    <script> \
        updateState(); \
        var interv = null; \
        function toggleState() { \
            if (interv) clearInterval(interv); \
            console.log('inv'); \
            interv = setInterval(updateState, 1800); \
            var xhttp = new XMLHttpRequest(); \
            xhttp.open('GET', 'rotate'); \
            xhttp.send(); \
        } \
        function updateState() { \
            var xhttp = new XMLHttpRequest(); \
            xhttp.onreadystatechange = function() { \
                if (this.readyState == 4 && this.status == 200) { \
                    console.log(this.responseText); \
                    var button = document.getElementById('btn'); \
                    if (this.responseText === '0') { \
                        button.innerHTML = 'M&#7903; c&#7917;a'; \
                        button.className = 'Open'; \
                        clearInterval(interv); \
                        interv = null; \
                    } else if (this.responseText === '1') { \
                        button.innerHTML = '&#272;&#243;ng c&#7917;a'; \
                        button.className = 'Close'; \
                        clearInterval(interv); \
                        interv = null; \
                    } else if (this.responseText === '2') { \
                        button.innerHTML = 'C&#7917;a &#273;ang &#273;&#243;ng...'; \
                        button.className = 'Closing'; \
                    } else if (this.responseText === '3') { \
                        button.innerHTML = 'C&#7917;a &#273;ang m&#7903;...'; \
                        button.className = 'Opening'; \
                    } \
                } \
            }; \
            xhttp.open('GET', 'get_state'); \
            xhttp.send(); \
        } \
        function toggleCredit() { \
            document.getElementById(\"credit-pannel\").classList.toggle(\"show\"); \
        } \
    </script> \
</head> \
<body> \
    <div id=\"header\">C&#7917;a Gi&#7871;ng Tr&#7901;i</div> \
    <button id=\"btn\" onclick=\"toggleState()\" class=\"Close\">Kh&#244;ng c&#243; k&#7871;t n&#7889;i</button> \
    <div onclick=\"toggleCredit()\" id=\"footer\"><b><u>&copy; 2020, MIS-CTU team.</b></u></div> \
    <div id=\"credit-pannel\"> \
        <h1 id=\"credit-header\">Skyline Window</h1> \
        <div id=\"credit-content\"> \
            <p><strong>&copy; 2020, MIS-CTU team (MIS  S.W.A.T)</strong> Licensed under the GNU v3 License.</p> \
            <ul> \
                <li>Khanh-Tran Nguyen</li> \
                <li>Minh-Luan Nguyen</li> \
                <li>Nhu-Phung Tran Thi</li> \
                <li>Anh-Khoi Tran</li> \
                <li>Minh-An Dao</li> \
            </ul> \
            <p> \
                This app would not be possible without the following libraries: \
            </p> \
            <ul> \
                <li><strong>esp32-wifi-manager</strong>, &copy; 2017-2020, Tony Pottier<br />Licensed under the MIT License.</li> \
                <li>SpinKit, &copy;  2015, Tobias Ahlin. Licensed under the MIT License.</li> \
                <li>jQuery, The jQuery Foundation. Licensed under the MIT License.</li> \
                <li>cJSON, &copy; 2009-2017, Dave Gamble and cJSON contributors. Licensed under the MIT License.</li> \
            </ul> \
        </div> \
        <button id=\"credit-btn\" onclick=\"toggleCredit()\">OK</button> \
    </div> \
</body> \
</html>"

//https://art-hanoi.com/vncode/