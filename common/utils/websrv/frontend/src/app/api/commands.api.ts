import { HttpClient } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { environment } from 'src/environments/environment';
export interface IInfo {
    name: string;
    value: string;
    type: IArgType;
    modifiable: boolean; //set command ?
}

export interface IModule {
    name: string;
}


export enum ILogLvl {
    error = "error",
    warn = "warn",
    analysis = "analysis",
    info = "info",
    debug = "debug",
    trace = "trace"
}

export enum ILogOutput {
    stdout = "stdout",
    telnet = "telnet",
    web = "web",
    file = "/tmp/<component>.log",
}

export enum IArgType {
    boolean = "boolean",
    list = "list",
    range = "range",
    number = "number",
    string = "string",
    configfile = "configfile"
}

export enum ICommandOptions {
    update = "update",
}

export interface IVariable {
    name: string;
    value: string;
    type: IArgType;
    modifiable: boolean; //set command ?
}

export interface ICommand {
    name: string;
    confirm?: string;
    question?: IQuestion;
    param?: IVariable;
    options?: ICommandOptions[];
}

export interface IColumn { //should use IVariable ?
    name: string;
    type: IArgType;
    modifiable: boolean; //set command ?
}

export type IRow = string[]

export interface IRow2 {
    params: IParam[],
    rawIndex: number,
    cmdName: string
}
export interface ITable {
    columns: IColumn[];
    rows: IRow[];
}
export interface IQuestion {
    display: string;
    pname: string;
    type: IArgType;
}
export interface IResp {
    display: string[],
    table?: ITable
}
export interface IParam {
    value: string,
    col?: IColumn
}

export const route = 'oaisoftmodem/';

@Injectable({
    providedIn: 'root',
})
export class CommandsApi {
    constructor(private httpClient: HttpClient) { }

    public readInfos$ = () => this.httpClient.get<IInfo[]>(environment.backend + route + 'variables/');

    public setInfo$ = (info: IInfo) => this.httpClient.post<IResp>(environment.backend + route + 'variables/', info);

    public readModules$ = () => this.httpClient.get<IModule[]>(environment.backend + route + 'commands/');

    public readVariables$ = (moduleName: string) => this.httpClient.get<IInfo[]>(environment.backend + route + moduleName + '/variables/');

    public readCommands$ = (moduleName: string) => this.httpClient.get<ICommand[]>(environment.backend + route + moduleName + '/commands/');

    public runCommand$ = (command: ICommand, moduleName: string) => {
        return this.httpClient.post<IResp>(environment.backend + route + moduleName + '/commands/', command);
    }

    public setVariable$ = (variable: IInfo, moduleName: string) => this.httpClient.post<IResp>(environment.backend + route + moduleName + '/variables/', variable);

    public setRow$ = (row: IRow2, moduleName: string) => this.httpClient.post<IResp>(environment.backend + route + moduleName + '/set/', row);

}