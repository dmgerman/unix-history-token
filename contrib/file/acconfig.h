begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Autoheader needs me */
end_comment

begin_undef
undef|#
directive|undef
name|PACKAGE
end_undef

begin_comment
comment|/* Autoheader needs me */
end_comment

begin_undef
undef|#
directive|undef
name|VERSION
end_undef

begin_comment
comment|/* Define if builtin ELF support is enabled.  */
end_comment

begin_undef
undef|#
directive|undef
name|BUILTIN_ELF
end_undef

begin_comment
comment|/* Define if ELF core file support is enabled.  */
end_comment

begin_undef
undef|#
directive|undef
name|ELFCORE
end_undef

begin_comment
comment|/* Define if the `long long' type works.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_LONG_LONG
end_undef

begin_comment
comment|/* Define to `unsigned char' if standard headers don't define.  */
end_comment

begin_undef
undef|#
directive|undef
name|uint8_t
end_undef

begin_comment
comment|/* Define to `unsigned short' if standard headers don't define.  */
end_comment

begin_undef
undef|#
directive|undef
name|uint16_t
end_undef

begin_comment
comment|/* Define to `unsigned int' if standard headers don't define.  */
end_comment

begin_undef
undef|#
directive|undef
name|uint32_t
end_undef

begin_comment
comment|/* Define to `unsigned long long', if available, or `unsigned long', if    standard headers don't define.  */
end_comment

begin_undef
undef|#
directive|undef
name|uint64_t
end_undef

begin_comment
comment|/* FIXME: These have to be added manually because autoheader doesn't know    about AC_CHECK_SIZEOF_INCLUDES.  */
end_comment

begin_comment
comment|/* The number of bytes in a uint8_t.  */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_UINT8_T
value|0
end_define

begin_comment
comment|/* The number of bytes in a uint16_t.  */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_UINT16_T
value|0
end_define

begin_comment
comment|/* The number of bytes in a uint32_t.  */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_UINT32_T
value|0
end_define

begin_comment
comment|/* The number of bytes in a uint64_t.  */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_UINT64_T
value|0
end_define

end_unit

