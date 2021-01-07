Action()
{

	int i;
	int j;
	int min;
	int NumForDelete;
	int mas[3];
	char* s;
	char* z;
	
	web_reg_find("Text=flightID",
		"SaveCount=Count",	             
		LAST);
	
	
	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);
	
		s = lr_eval_string("{Count}");
		i = atoi(s);
		lr_output_message("Number of Tickets on Page in GetAnswer: %s",lr_eval_string("{Count}"));
		lr_output_message("");
		
		if (i == 3) {
			
			web_reg_save_param_ex(
			"ParamName=flightID1",
			"LB=flightID\" value=\"",
			"RB=\"",
			"Ordinal=1",
			SEARCH_FILTERS,
			LAST);
			
			web_reg_save_param_ex(
			"ParamName=flightID2",
			"LB=flightID\" value=\"",
			"RB=\"",
			"Ordinal=2",
			SEARCH_FILTERS,
			LAST);
			
			web_reg_save_param_ex(
			"ParamName=flightID3",
			"LB=flightID\" value=\"",
			"RB=\"",
			"Ordinal=3",
			SEARCH_FILTERS,
			LAST);
			
			web_reg_save_param_ex(
			"ParamName=TotalCost1",
			"LB=Total Charge: $ ",
			"RB= <BR/>",
			"Ordinal=1",
			SEARCH_FILTERS,
			LAST);
			
			web_reg_save_param_ex(
			"ParamName=TotalCost2",
			"LB=Total Charge: $ ",
			"RB= <BR/>",
			"Ordinal=2",
			SEARCH_FILTERS,
			LAST);
			
			web_reg_save_param_ex(
			"ParamName=TotalCost3",
			"LB=Total Charge: $ ",
			"RB= <BR/>",
			"Ordinal=3",
			SEARCH_FILTERS,
			LAST);
			
			web_url("welcome.pl", 
			"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
			"Snapshot=t4.inf", 
			"Mode=HTML", 
			LAST);
			
			lr_output_message("Number of flightID1: %s",lr_eval_string("{flightID1}"));
			lr_output_message("Cost of flightID1: %s",lr_eval_string("{TotalCost1}"));
			lr_output_message("Number of flightID2: %s",lr_eval_string("{flightID2}"));
			lr_output_message("Cost of flightID2: %s",lr_eval_string("{TotalCost2}"));
			lr_output_message("Number of flightID3: %s",lr_eval_string("{flightID3}"));
			lr_output_message("Cost of flightID3: %s",lr_eval_string("{TotalCost3}"));
			lr_output_message("");
			
			z = lr_eval_string("{TotalCost1}");
			mas[0] = atoi(z);
			z = lr_eval_string("{TotalCost2}");
			mas[1] = atoi(z);
			z = lr_eval_string("{TotalCost3}");
			mas[2] = atoi(z);
			
			min = mas[0];
			
			for(j=0; j<3; j++) {
				
				if (mas[j] <= min) {
					
					min = mas[j];
					
					NumForDelete = (j+1);
					
				}
				
			}
			
			lr_save_int(min, "MIN");
			lr_output_message("MINIMUM cost of ticket: %s",lr_eval_string("{MIN}"));
			lr_save_int(NumForDelete, "NumberForDelete");
			lr_output_message("Number ticket for DELETE: %s",lr_eval_string("{NumberForDelete}"));
			
			web_submit_data("itinerary.pl", 
			"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
			"Snapshot=t5.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=flightID", "Value={flightID1}", ENDITEM, 
			"Name=flightID", "Value={flightID2}", ENDITEM, 
			"Name={NumberForDelete}", "Value=on", ENDITEM, 
			"Name=flightID", "Value={flightID3}", ENDITEM, 
			"Name=.cgifields", "Value=1", ENDITEM, 
			"Name=.cgifields", "Value=3", ENDITEM, 
			"Name=.cgifields", "Value=2", ENDITEM, 
			"Name=removeFlights.x", "Value=39", ENDITEM, 
			"Name=removeFlights.y", "Value=14", ENDITEM, 
			LAST);
			

		} else {
		
			lr_output_message("Number of Tickets don't equals 3, You need to add ticket");
		}

	return 0;
}