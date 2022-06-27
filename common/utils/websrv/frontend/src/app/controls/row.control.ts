import { FormArray, FormGroup } from '@angular/forms';
import { IRow2 } from '../api/commands.api';
import { ParamFC } from './param.control';

const enum RowFCN {
  params = 'params',
}

export class RowCtrl extends FormGroup {

  constructor(public row: IRow2) {
    super({});

    this.addControl(RowFCN.params, new FormArray(row.params.map(param => new ParamFC(param))))
  }

  api() {

    const doc: IRow2 = {
      rawIndex: this.row.rawIndex,
      cmdName: this.row.cmdName,
      params: this.paramsFA.controls.map(fc => (fc as ParamFC).api())
    }
    return doc

  }

  get paramsFA() {
    return this.get(RowFCN.params) as FormArray;
  }

  set paramsFA(fa: FormArray) {
    this.setControl(RowFCN.params, fa);
  }

}
