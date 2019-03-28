type messageType = (ReasonReact.reactElement, option(float), option(unit => unit)) => Js.Promise.t(unit);

[@bs.scope "message"] [@bs.module "antd"]
external callInfo: messageType = "info";
[@bs.scope "message"] [@bs.module "antd"]
external callError: messageType = "error";
[@bs.scope "message"] [@bs.module "antd"]
external callSuccess: messageType = "success";
[@bs.scope "message"] [@bs.module "antd"]
external callWarning: messageType = "warning";
[@bs.scope "message"] [@bs.module "antd"]
external callLoading: messageType = "loading";
[@bs.scope "message"] [@bs.module "antd"]

[%bs.raw {|require("antd/lib/message/style")|}];

let info = (~content, ~duration=?, ~onClose=?, ()) => {
  callInfo(content, duration, onClose);
};

let error = (~content, ~duration=?, ~onClose=?, ()) => {
  callError(content, duration, onClose);
};

let success = (~content, ~duration=?, ~onClose=?, ()) => {
  callSuccess(content, duration, onClose);
};

let warning = (~content, ~duration=?, ~onClose=?, ()) => {
  callSuccess(content, duration, onClose);
};

let loading = (~content, ~duration=?, ~onClose=?, ()) => {
  callLoading(content, duration, onClose);
};
