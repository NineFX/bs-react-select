open BsReactSelect;

type item = {
  .
  "value": string,
  "label": string,
};

type action =
  | Change(array(item));

type state = {selectedItem: array(item)};

[@react.component]
let make = (~options) => {

  let initialState = {selectedItem: [|{"value": "two", "label": "Two"}, {"value": "two", "label": "Two"}|]};

  let reducer = (_state, action) =>
    switch (action) {
      | Change(selectedItem) => {
        Js.log2("SELECTED ITEMS: ", selectedItem);
        {selectedItem: selectedItem};
      }
      };

  let (state, send) = React.useReducer(reducer, initialState);

  <SelectMulti
    options
    value={`Arr(state.selectedItem)}
    onChange={selected => {
      Js.log2("SELECTED ARR: ", selected);
      send(Change(selected));
    }}
  />;

};
