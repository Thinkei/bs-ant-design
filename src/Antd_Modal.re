[@bs.module "antd"] external modal: ReasonReact.reactClass = "Modal";

[%bs.raw {|require("antd/lib/modal/style")|}];

[@bs.obj]
external makeProps:
  (
    ~visible: bool=?,
    ~confirmLoading: bool=?,
    ~title: string=?,
    ~closable: bool=?,
    ~onOk: ReactEvent.Mouse.t => unit=?,
    ~onCancel: ReactEvent.Mouse.t => unit=?,
    ~afterClose: unit => unit=?,
    ~centered: bool=?,
    ~width: int=?,
    ~footer: ReasonReact.reactElement=?,
    ~okText: string=?,
    ~okType: string=?,
    ~cancelText: string=?,
    ~zIndex: int=?,
    ~okCancel: bool=?,
    ~destroyOnClose: bool=?,
    ~wrapClassName: string=?,
    ~maskTransitionName: string=?,
    ~transitionName: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~bodyStyle: ReactDOMRe.Style.t=?,
    ~mask: bool=?,
    ~maskClosable: bool=?,
    ~maskStyle: ReactDOMRe.Style.t=?,
    ~keyboard: bool=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~visible=?,
      ~confirmLoading=?,
      ~title=?,
      ~closable=?,
      ~onOk=?,
      ~onCancel=?,
      ~afterClose=?,
      ~centered=?,
      ~width=?,
      ~footer=?,
      ~okText=?,
      ~okType=?,
      ~cancelText=?,
      ~zIndex=?,
      ~okCancel=?,
      ~destroyOnClose=?,
      ~wrapClassName=?,
      ~maskTransitionName=?,
      ~transitionName=?,
      ~className=?,
      ~style=?,
      ~bodyStyle=?,
      ~mask=?,
      ~maskClosable=?,
      ~maskStyle=?,
      ~keyboard=?,
      ~children=?,
    ) => {
  ReasonReact.wrapJsForReason(
    ~reactClass=modal,
    ~props=
      makeProps(
        ~visible?,
        ~confirmLoading?,
        ~title?,
        ~closable?,
        ~onOk?,
        ~onCancel?,
        ~afterClose?,
        ~centered?,
        ~width?,
        ~footer?,
        ~okText?,
        ~okType=?Belt.Option.map(okType, Antd_Button.buttonTypeToJs),
        ~cancelText?,
        ~zIndex?,
        ~okCancel?,
        ~destroyOnClose?,
        ~wrapClassName?,
        ~maskTransitionName?,
        ~transitionName?,
        ~className?,
        ~style?,
        ~bodyStyle?,
        ~mask?,
        ~maskClosable?,
        ~maskStyle?,
        ~keyboard?,
        (),
      ),
    children,
  );
};
