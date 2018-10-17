struct Console {
    int version = -1, build = -1, bound = 9600;
    String name, s_name;
    bool debug = false;

    String functions[10];
    int adds = 0;
    bool actives[10];

    void start()
    {
        Serial.begin(getBound());
    }

    String setName(String s)
    {
        return name = s;
    }

    String setShortName(String s)
    {
        return s_name = s;
    }

    String getName()
    {
        return name;
    }

    String getShortName()
    {
        return s_name;
    }

    int setBound(int i)
    {
        return bound = i;
    }

    int getBound()
    {
        return bound;
    }

    void isDebug()
    {
        return debug;
    }

    bool changeDebug()
    {
        return debug ? debug = false : debug = true;
    }

    String isActive(bool b)
    {
        return b ? "Enable" : "Disable";
    }

    String isActive(int i)
    {
        return actives[i] ? "Enable" : "Disable";
    }

    bool isActive(String s)
    {
        for (int i = 0; i < sizeof(functions) / sizeof(functions[0]); i++)
        {
            String func = functions[i];
            if (func == s)
            {
                return actives[i];
            }
        }   
    }

    int setVersion(int i)
    {
        return version = i;
    }

    int setBuild(int i)
    {
        return build = i;
    }

    int getVersion()
    {
        return version;
    }

    int getBuild()
    {
        return build;
    }

    void sendMessage(String message)
    {
        Serial.println(message);
    }

    void addFunction(String function)
    {
        functions[adds] = function;
        adds++;
    }

    void changeFunctionState(String function)
    {
        for (int i = 0; i < sizeof(functions) / sizeof(functions[0]); i++)
        {
            String func = functions[i];
            if (func == function)
            {
                actives[i] ? actives[i] = false : actives[i] = true;
            }
        }
    }

    void sendMain()
    {
        sendMessage(String(getName() + " v" + getVersion() + "." + getBuild()));
        sendMessage(String("Debug Mode " + isActive(debug)));

        for (int i = 0; i < 20; i++)
        {
            Serial.print("-");
            if (i >= 19)
            {
                Serial.println("-");
            }
        }

        for (int i = 0; i < sizeof(functions) / sizeof(functions[0]); i++)
        {
            String function = functions[i];
            if (function != "")
            {
                sendMessage(String(functions[i] + ": " + isActive(i)));
            }
        }

        sendMessage("");
    }
};
