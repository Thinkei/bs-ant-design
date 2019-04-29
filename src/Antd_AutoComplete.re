[@bs.module "antd/lib/auto-complete"]
external autoComplete: ReasonReact.reactClass = "default";

[%bs.raw {|require("antd/lib/auto-complete/style")|}];

[@bs.obj]
external makeProps:
  (
    ~dataSource: array(string)=?,
    ~value: string=?,
    ~defaultValue: string=?,
    ~onChange: ReactEvent.Form.t => unit=?,
    ~onPressEnter: ReactEvent.Keyboard.t => unit=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~dataSource=?,
      ~value=?,
      ~defaultValue=?,
      ~onChange=?,
      ~onPressEnter=?,
      ~className=?,
      ~style=?,
      ~children=?,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=autoComplete,
    ~props=
      makeProps(
        ~dataSource?,
        ~value?,
        ~defaultValue?,
        ~onChange?,
        ~onPressEnter?,
        ~className?,
        ~style?,
        (),
      ),
    children,
  );

module TextArea = {
  [@bs.module "antd/lib/input/TextArea"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~value=?,
        ~defaultValue=?,
        ~onChange=?,
        ~onPressEnter=?,
        ~onBlur=?,
        ~className=?,
        ~style=?,
        ~children=?,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~value?,
          ~defaultValue?,
          ~onChange?,
          ~onPressEnter?,
          ~onBlur?,
          ~className?,
          ~style?,
          (),
        ),
      children,
    );
};
