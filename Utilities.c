void multiplePinMode(int pins[], int mode)
{
    for(int i = 0; i< sizeof(pins); i++)
    {
        pinMode(pins[i], mode);
    }
}

void multipleDigitalWrite(int pins[], int mode)
{
    for(int i = 0; i< sizeof(pins); i++)
    {
        digitalWrite(pins[i], mode);
    }
}

void configureOutputs(int pins[]){
    multiplePinMode(pins, 1);
}

void configureInputs(int pins[]){
    multiplePinMode(pins, 0);
}