[@bs.module "antd"] external table: ReasonReact.reactClass = "Table";

[%bs.raw {|require("antd/lib/table/style")|}];

module TableProps = {
  [@bs.deriving jsConverter]
  type size = [ | `default | `middle | `small];

  module ColumnProps = {
    [@bs.deriving abstract]
    type t('a) = {
      [@bs.optional]
      title: string,
      [@bs.optional]
      key: string,
      [@bs.optional]
      dataIndex: string,
      [@bs.optional]
      width: int,
      [@bs.optional]
      render:
        (~text: string, ~record: 'a, ~index: int) => ReasonReact.reactElement,
    };
  };

  [@bs.deriving abstract]
  type t('a) = {
    dataSource: array('a),
    columns: array(ColumnProps.t('a)),
    [@bs.optional]
    prefixCls: string,
    [@bs.optional]
    dropdownPrefixCls: string,
    [@bs.optional]
    size: string,
    [@bs.optional]
    bodyStyle: ReactDOMRe.Style.t,
    [@bs.optional]
    className: string,
    [@bs.optional]
    style: ReactDOMRe.Style.t,
    [@bs.optional]
    loading: bool,
    [@bs.optional]
    rowKey: string,
  };

  let make = t;
  let make_column = ColumnProps.t;
};

let make =
    (
      ~prefixCls=?,
      ~dropdownPrefixCls=?,
      ~size=?,
      ~bodyStyle=?,
      ~className=?,
      ~style=?,
      ~loading=?,
      ~rowKey=?,
      ~dataSource,
      ~columns,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=table,
    ~props=
      TableProps.make(
        ~dataSource,
        ~columns,
        ~prefixCls?,
        ~dropdownPrefixCls?,
        ~size=?Belt.Option.map(size, TableProps.sizeToJs),
        ~bodyStyle?,
        ~className?,
        ~style?,
        ~loading?,
        ~rowKey?,
        (),
      ),
    children,
  );
