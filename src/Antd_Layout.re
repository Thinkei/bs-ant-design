open Antd_Helpers;

[@bs.module "antd/lib/layout"]
external layout: ReasonReact.reactClass = "default";

[%bs.raw {|require("antd/lib/layout/style")|}];

[@bs.obj]
external makeProps:
  (~id: string=?, ~className: string=?, ~style: ReactDOMRe.Style.t=?, unit) =>
  _ =
  "";

let make = (~id=?, ~className=?, ~style=?, ~children=?) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=layout,
    ~props=makeProps(~id?, ~className?, ~style?, ()),
    children,
  );

module Header = {
  [@bs.module "antd/lib/layout"]
  external header: ReasonReact.reactClass = "default";
  let make = (~id=?, ~className=?, ~style=?, ~children=?) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=header,
      ~props=makeProps(~id?, ~className?, ~style?, ()),
      children,
    );
};

module Footer = {
  [@bs.scope "default"] [@bs.module "antd/lib/layout/layout"]
  external footer: ReasonReact.reactClass = "Footer";
  let make = (~id=?, ~className=?, ~style=?, ~children=?) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=footer,
      ~props=makeProps(~id?, ~className?, ~style?, ()),
      children,
    );
};

module Content = {
  [@bs.scope "default"] [@bs.module "antd/lib/layout/layout"]
  external content: ReasonReact.reactClass = "Content";
  let make = (~id=?, ~className=?, ~style=?, ~children=?) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=content,
      ~props=makeProps(~id?, ~className?, ~style?, ()),
      children,
    );
};

module Sider = {
  [@bs.module "antd/lib/layout/Sider"]
  external sider: ReasonReact.reactClass = "default";
  [@bs.deriving {jsConverter: newType}]
  type collapseType = [ | `clickTrigger | `responsive];
  [@bs.obj]
  external makeProps:
    (
      ~style: ReactDOMRe.Style.t=?,
      ~prefixCls: string=?,
      ~className: string=?,
      ~collapsible: bool=?,
      ~collapsed: bool=?,
      ~defaultCollapsed: bool=?,
      ~reverseArrow: bool=?,
      ~onCollapse: (bool, abs_collapseType) => unit=?,
      ~trigger: ReasonReact.reactElement=?,
      ~width: int=?,
      ~collapsedWidth: int=?,
      ~breakpoint: string=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~style=?,
        ~prefixCls=?,
        ~className=?,
        ~collapsible=?,
        ~collapsed=?,
        ~defaultCollapsed=?,
        ~reverseArrow=?,
        ~onCollapse=?,
        ~trigger=?,
        ~width=?,
        ~collapsedWidth=?,
        ~breakpoint=?,
        ~children=?,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=sider,
      ~props=
        makeProps(
          ~style?,
          ~prefixCls?,
          ~className?,
          ~collapsible?,
          ~collapsed?,
          ~defaultCollapsed?,
          ~reverseArrow?,
          ~onCollapse=?
            Js.Option.map(
              (. fn) => {
                /* TODO: Is there any perf cost of defining the function here */
                let reF = (fn, a, b) => fn(a, collapseTypeFromJs(b));
                reF(fn);
              },
              onCollapse,
            ),
          ~trigger?,
          ~width?,
          ~collapsedWidth?,
          ~breakpoint=?
            Js.Option.map((. b) => breakpointToJs(b), breakpoint),
          (),
        ),
      children,
    );
};
