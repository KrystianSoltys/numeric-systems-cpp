#include "ui.hpp"
#include <iostream>

int main()
{
    std::string msg = "";
    while(true)
    {
        try
        {
            switch(ui::MainMenu(msg))
            {
            case 1:
            {
				ui::ManualPart();
                break;
            }
            case 2:
            {
				ui::FilePart();
                break;
            }
            case 3:
            {
				msg = "No options yet.";
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
			default:
			{
				msg = "Incorrect module number.";
			}
            }
        }
        catch(BadFile& exc)
        {
			msg = exc.what();
            continue;
        }
        catch(std::out_of_range& exc)
        {
			msg = exc.what();
            continue;
        }
        catch(BadDataInFile& exc)
        {
			msg = exc.what();
            continue;
        }
		catch (CalculationExc& exc)
		{
			msg = exc.what();
			continue;
		}
        catch(...)
        {
            break;
        }

    }
	std::exit(EXIT_FAILURE);
}
