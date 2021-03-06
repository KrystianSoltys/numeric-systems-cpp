#include "ui.hpp"
#include "log.hpp"
#include "options.hpp"
#include <iostream>

auto main() -> int
{
	Log log(DEFAULT_LOG_FILENAME);
    Options opt(DEFAULT_OPT_FILENAME, DEFAULT_TR_FILENAME);
    UI ui(opt);
    std::string msg = "";
    bool end = false;
    while(!end)
    {
        try
        {
            switch(ui.MainMenu(msg))
            {
            case 1:
            {
				log.AddToLog("Entered Manual Module");
				ui.ManualPart();
                break;
            }
            case 2:
            {
				log.AddToLog("Entered File Module");
				ui.FilePart();
                break;
            }
            case 3:
            {
				log.AddToLog("Entered Options Module");
                ui.OptionsMenu();
                break;
            }
            case 4:
            {
				log.AddToLog("Entered About Module");
                ui.About();
                break;
            }
            case 0:
            {
                ui.cls();
				log.AddToLog(DEFAULT_GOODBYE_MESS);
                std::cout << ui.GetString(18) << "\n";
                ui.Wait();
                std::exit(EXIT_SUCCESS);
            }
			default:
			{
				log.AddToLog("Provided incorrect module number");
				msg = ui.GetString(19);
			}
            }
        }
        catch(BadFile& exc)
        {
			log.AddToLog(exc.what(), true);
			msg = exc.what();
            continue;
        }
        catch(std::out_of_range& exc)
        {
			log.AddToLog(exc.what(), true);
			msg = exc.what();
            continue;
        }
        catch(BadDataInFile& exc)
        {
			log.AddToLog(exc.what(), true);
			msg = exc.what();
            continue;
        }
		catch (CalculationExc& exc)
		{
			log.AddToLog(exc.what(), true);
			msg = exc.what();
			continue;
		}
		catch (BadLogFile& exc)
		{
			msg = exc.what();
			continue;
		}
		catch (std::exception& exc)
		{
			log.AddToLog(exc.what(), true);
            end = true;
			break;
		}
        catch(...)
        {
			log.AddToLog("Unknown exception has been caught, please contact devs", true);
            end = true;
            break;
        }

    }
	log.AddToLog(DEFAULT_CRITICAL_MESS);
	std::exit(EXIT_FAILURE);
}
