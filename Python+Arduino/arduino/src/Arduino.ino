
String data = "";
boolean is_complete = false;
boolean ack = false;
boolean up = false; //to check if there is someoen reading

void setup()
{
    //Initialize serial and wait for port to open:
    Serial.begin(9600); //baud rate for arduino 1
    while (!Serial)
    {
        ; // wait for serial port to connect. Needed for native USB port only
    }
    // prints title with ending line break
    Serial.println("Conneted, waiting for Hand Sake\n");
    data.reserve(3); // reserve  3 bytes for the string
}

void loop()
{
    if (up)
    {
        //Print some data, and wait to ACk to print again
        if (ack)
        {
            Serial.print("Hey, are u up.");
            Serial.println(" Ok, I leave u this.");
            delay(1000);
            ack = false;
        }
    }
    //Prints what he recived
    if (is_complete)
    {
        //Print the string
        Serial.print("I recived: ");
        Serial.println(data);
        //Clear the string
        data = "";
        is_complete = false;
    }
}

void serialEvent()
{
    while (Serial.available())
    {
        // get the new byte:
        char inChar = (char)Serial.read();
        // add it to the inputString:
        if (inChar == '\n')
        {
            is_complete = true;
        }
        else
        {
            data += inChar;
        }
        // if the incoming character is a newline, set a flag so the main loop can
        // do something about it:
    }

    if (data == "UP ")
    {
        ack = true;
        up = true;
    }
    else if (data == "EXI")
    {
        up = false;
        Serial.println("Bye");
    }
}