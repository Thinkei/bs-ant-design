[@bs.module "antd"] external tooltip: ReasonReact.reactClass = "Tooltip";

[%bs.raw {|require("antd/lib/tooltip/style")|}];

[@bs.deriving jsConverter]
type placementType = [
  | `top
  | `left
  | `right
  | `bottom
  | `topLeft
  | `topRight
  | `bottomLeft
  | `bottomRight
  | `leftTop
  | `leftBottom
  | `rightTop
  | `rightBottom
];

[@bs.obj]
external makeProps:
  (
    ~title: ReasonReact.reactElement,
    ~overlay: ReasonReact.reactElement=?,
    ~placement: string=?,
    unit
  ) =>
  _ =
  "";

let make = (~title, ~overlay=?, ~placement=?, ~children=?) => {
  ReasonReact.wrapJsForReason(
    ~reactClass=tooltip,
    ~props=
      makeProps(
        ~title,
        ~overlay?,
        ~placement=?Belt.Option.map(placement, placementTypeToJs),
        (),
      ),
    children,
  );
};
