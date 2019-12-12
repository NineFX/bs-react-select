open Belt;
open BsReactSelect;

type item = {
  .
  "value": string,
  "label": string,
};

type action =
  | Change(option(item));

type state = {selectedItem: option(item)};

[@react.component]
let make = (~options) => {

  let initialState = {selectedItem: None};

  let reducer = (_state, action) =>
    switch (action) {
      | Change(selectedItem) =>{selectedItem: selectedItem}
      };

  let (state, send) = React.useReducer(reducer, initialState);

  <Select
    options
    value=
      ?state.selectedItem->Option.map(item => `Val(item))
    onChange={
      selected => {
        Js.log("onChange");
        send(Change(selected));
      }
    }
    arrowRenderer={_ => <div> {React.string("+")} </div>}
    filterOptions={`Func((~options, ~filter as _filter) => options)}
    placeholder={`Str("Select something..")}
  />;
};
