begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Number of bits in a `char'.  */
end_comment

begin_define
define|#
directive|define
name|CHAR_BIT
value|8
end_define

begin_comment
comment|/* No multibyte characters supported yet.  */
end_comment

begin_define
define|#
directive|define
name|MB_LEN_MAX
value|1
end_define

begin_comment
comment|/* Minimum and maximum values a `signed char' can hold.  */
end_comment

begin_define
define|#
directive|define
name|SCHAR_MIN
value|(-128)
end_define

begin_define
define|#
directive|define
name|SCHAR_MAX
value|127
end_define

begin_comment
comment|/* Maximum value an `unsigned char' can hold.  (Minimum is 0).  */
end_comment

begin_define
define|#
directive|define
name|UCHAR_MAX
value|255U
end_define

begin_comment
comment|/* Minimum and maximum values a `char' can hold.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__CHAR_UNSIGNED__
end_ifdef

begin_define
define|#
directive|define
name|CHAR_MIN
value|0
end_define

begin_define
define|#
directive|define
name|CHAR_MAX
value|255U
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CHAR_MIN
value|(-128)
end_define

begin_define
define|#
directive|define
name|CHAR_MAX
value|127
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Minimum and maximum values a `signed short int' can hold.  */
end_comment

begin_define
define|#
directive|define
name|SHRT_MIN
value|(-32768)
end_define

begin_define
define|#
directive|define
name|SHRT_MAX
value|32767
end_define

begin_comment
comment|/* Maximum value an `unsigned short int' can hold.  (Minimum is 0).  */
end_comment

begin_define
define|#
directive|define
name|USHRT_MAX
value|65535U
end_define

begin_comment
comment|/* Minimum and maximum values a `signed int' can hold.  */
end_comment

begin_define
define|#
directive|define
name|INT_MIN
value|(-INT_MAX-1)
end_define

begin_define
define|#
directive|define
name|INT_MAX
value|2147483647
end_define

begin_comment
comment|/* Maximum value an `unsigned int' can hold.  (Minimum is 0).  */
end_comment

begin_define
define|#
directive|define
name|UINT_MAX
value|4294967295U
end_define

begin_comment
comment|/* Minimum and maximum values a `signed long int' can hold.    (Same as `int').  */
end_comment

begin_define
define|#
directive|define
name|LONG_MIN
value|(-LONG_MAX-1)
end_define

begin_define
define|#
directive|define
name|LONG_MAX
value|2147483647
end_define

begin_comment
comment|/* Maximum value an `unsigned long int' can hold.  (Minimum is 0).  */
end_comment

begin_define
define|#
directive|define
name|ULONG_MAX
value|4294967295U
end_define

end_unit

