[@bs.module "antd/lib/select"]
external select: ReasonReact.reactClass = "default";

[%bs.raw {|require("antd/lib/select/style")|}];

[@bs.obj]
external makeProps:
  (
    ~value: string=?,
    ~defaultValue: string=?,
    ~onChange: string => unit=?,
    ~className: string=?,
    unit
  ) =>
  _ =
  "";
let make = (~value=?, ~defaultValue=?, ~onChange=?, ~className=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=select,
    ~props=makeProps(~value?, ~defaultValue?, ~onChange?, ~className?, ()),
    children,
  );

module Option = {
  [@bs.module "antd/lib/select/Option"]
  external reactClass: ReasonReact.reactClass = "default";

  [@bs.obj] external makeProps: (~value: string, ~title: string=?) => _ = "";

  let make = (~value, ~title=?) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~value, ~title?),
    );
};