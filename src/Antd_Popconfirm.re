[@bs.module "antd"] external popconfirm: ReasonReact.reactClass = "Popconfirm";

[%bs.raw {|require("antd/lib/popconfirm/style")|}];

[@bs.obj]
external makeProps:
  (
    ~title: ReasonReact.reactElement,
    ~onConfirm: ReactEvent.Mouse.t => unit=?,
    ~onCancel: ReactEvent.Mouse.t => unit=?,
    ~okText: ReasonReact.reactElement=?,
    ~okType: string=?,
    ~cancelText: ReasonReact.reactElement=?,
    ~onVisibleChange: bool => unit=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~title,
      ~onConfirm=?,
      ~onCancel=?,
      ~okText=?,
      ~okType=?,
      ~cancelText=?,
      ~onVisibleChange=?,
      children,
    ) => {
  ReasonReact.wrapJsForReason(
    ~reactClass=modalpopconfirm,
    ~props=
      makeProps(
        ~title,
        ~onConfirm?,
        ~onCancel?,
        ~okText?,
        ~okType=?Belt.Option.map(okType, Antd_Button.buttonTypeToJs),
        ~cancelText?,
        ~onVisibleChange?,
        (),
      ),
    children,
  );
};
