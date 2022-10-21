import { HttpClient } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { environment } from 'src/environments/environment';
import {  map } from 'rxjs/operators';
import { Observable } from 'rxjs';

export interface HelpRequest { 
    module:    string;
    command: string;
    object:    string;
}

export interface HelpResp {   
    text: string;
}
const hlproute = 'oaisoftmodem/helpfiles/';

@Injectable({
    providedIn: 'root',
})

export class HelpApi {
    constructor(private httpClient: HttpClient) { }

    public getHelp$ = (req : HelpRequest) => this.httpClient.get<HelpResp>(environment.backend + hlproute + req.module + "_" + req.command + "_" +req.object + ".html",{observe: 'response'});

    public getHelpText(module:string, command:string, object:string): Observable<string>{
		  return this.getHelp$({module:module, command:command,object:object}).pipe( map (
                (response => {return (response.status == 201)?response.body!.text:"";}),
	   ) ); //pipe
		   
	}
}
