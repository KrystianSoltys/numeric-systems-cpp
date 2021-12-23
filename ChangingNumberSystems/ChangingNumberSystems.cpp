﻿#include "ui.hpp"
#include <iostream>

int main()
{
    std::string msg;
    while(true)
    {
        msg = "";
        try
        {
            switch(ui::MainMenu(msg))
            {
            case 1:
                {
                    ui::ManualPart()
                    break;
                }
            case 2:
                {
                    ui::FilePart()
                    break;
                }
            case 3:
                {
                    //options here
                    break;
                }
            case 4:
                {
                    ui::About();
                    break;
                }
            case 0:
                {
                    cls();
                    std::cout << "See you again!\n";
                    std::exit(EXIT_SUCCESS);
                }
            }
        }
        catch(BadFile& exc)
        {
            msg = "Problem with file occurred.";
            continue;
        }
        catch(std::out_of_range& exc)
        {
            msg = "Provided base number out of range";
            continue;
        }
        catch(BadDataInFile& exc)
        {
            msg = "Data provided in file is not valid";
            continue;
        }
        catch(...)
        {
            break;
        }

    }
	return EXIT_FAILURE;
}
