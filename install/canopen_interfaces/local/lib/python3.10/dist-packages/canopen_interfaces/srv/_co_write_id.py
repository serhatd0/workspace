# generated from rosidl_generator_py/resource/_idl.py.em
# with input from canopen_interfaces:srv/COWriteID.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_COWriteID_Request(type):
    """Metaclass of message 'COWriteID_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('canopen_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'canopen_interfaces.srv.COWriteID_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__co_write_id__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__co_write_id__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__co_write_id__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__co_write_id__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__co_write_id__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class COWriteID_Request(metaclass=Metaclass_COWriteID_Request):
    """Message class 'COWriteID_Request'."""

    __slots__ = [
        '_nodeid',
        '_index',
        '_subindex',
        '_data',
        '_type',
    ]

    _fields_and_field_types = {
        'nodeid': 'uint8',
        'index': 'uint16',
        'subindex': 'uint8',
        'data': 'uint32',
        'type': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.nodeid = kwargs.get('nodeid', int())
        self.index = kwargs.get('index', int())
        self.subindex = kwargs.get('subindex', int())
        self.data = kwargs.get('data', int())
        self.type = kwargs.get('type', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.nodeid != other.nodeid:
            return False
        if self.index != other.index:
            return False
        if self.subindex != other.subindex:
            return False
        if self.data != other.data:
            return False
        if self.type != other.type:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def nodeid(self):
        """Message field 'nodeid'."""
        return self._nodeid

    @nodeid.setter
    def nodeid(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'nodeid' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'nodeid' field must be an unsigned integer in [0, 255]"
        self._nodeid = value

    @builtins.property
    def index(self):
        """Message field 'index'."""
        return self._index

    @index.setter
    def index(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'index' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'index' field must be an unsigned integer in [0, 65535]"
        self._index = value

    @builtins.property
    def subindex(self):
        """Message field 'subindex'."""
        return self._subindex

    @subindex.setter
    def subindex(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'subindex' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'subindex' field must be an unsigned integer in [0, 255]"
        self._subindex = value

    @builtins.property
    def data(self):
        """Message field 'data'."""
        return self._data

    @data.setter
    def data(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'data' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'data' field must be an unsigned integer in [0, 4294967295]"
        self._data = value

    @builtins.property  # noqa: A003
    def type(self):  # noqa: A003
        """Message field 'type'."""
        return self._type

    @type.setter  # noqa: A003
    def type(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'type' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'type' field must be an unsigned integer in [0, 255]"
        self._type = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_COWriteID_Response(type):
    """Metaclass of message 'COWriteID_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('canopen_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'canopen_interfaces.srv.COWriteID_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__co_write_id__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__co_write_id__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__co_write_id__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__co_write_id__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__co_write_id__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class COWriteID_Response(metaclass=Metaclass_COWriteID_Response):
    """Message class 'COWriteID_Response'."""

    __slots__ = [
        '_success',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.success != other.success:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value


class Metaclass_COWriteID(type):
    """Metaclass of service 'COWriteID'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('canopen_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'canopen_interfaces.srv.COWriteID')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__co_write_id

            from canopen_interfaces.srv import _co_write_id
            if _co_write_id.Metaclass_COWriteID_Request._TYPE_SUPPORT is None:
                _co_write_id.Metaclass_COWriteID_Request.__import_type_support__()
            if _co_write_id.Metaclass_COWriteID_Response._TYPE_SUPPORT is None:
                _co_write_id.Metaclass_COWriteID_Response.__import_type_support__()


class COWriteID(metaclass=Metaclass_COWriteID):
    from canopen_interfaces.srv._co_write_id import COWriteID_Request as Request
    from canopen_interfaces.srv._co_write_id import COWriteID_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
