begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* FREEBSD_NATIVE is defined when gcc is integrated into the FreeBSD    source tree so it can be configured appropriately without using    the GNU configure/build mechanism. */
end_comment

begin_undef
undef|#
directive|undef
name|FREEBSD_NATIVE
end_undef

begin_define
define|#
directive|define
name|FREEBSD_NATIVE
value|1
end_define

begin_undef
undef|#
directive|undef
name|SYSTEM_INCLUDE_DIR
end_undef

begin_comment
comment|/* We don't need one for now. */
end_comment

begin_undef
undef|#
directive|undef
name|TOOL_INCLUDE_DIR
end_undef

begin_comment
comment|/* We don't need one for now. */
end_comment

begin_undef
undef|#
directive|undef
name|LOCAL_INCLUDE_DIR
end_undef

begin_comment
comment|/* We don't wish to support one. */
end_comment

begin_comment
comment|/* Look for the include files in the system-defined places.  */
end_comment

begin_define
define|#
directive|define
name|GPLUSPLUS_INCLUDE_DIR
value|PREFIX"/include/g++"
end_define

begin_define
define|#
directive|define
name|GCC_INCLUDE_DIR
value|PREFIX"/include"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CROSS_COMPILE
end_ifdef

begin_define
define|#
directive|define
name|CROSS_INCLUDE_DIR
value|PREFIX"/include"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STANDARD_INCLUDE_DIR
value|PREFIX"/include"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Under FreeBSD, the normal location of the compiler back ends is the    /usr/libexec directory.     ``cc --print-search-dirs'' gives:    install: STANDARD_EXEC_PREFIX/(null)    programs: /usr/libexec/<OBJFORMAT>/:STANDARD_EXEC_PREFIX:MD_EXEC_PREFIX    libraries: MD_EXEC_PREFIX:MD_STARTFILE_PREFIX:STANDARD_STARTFILE_PREFIX */
end_comment

begin_undef
undef|#
directive|undef
name|TOOLDIR_BASE_PREFIX
end_undef

begin_comment
comment|/* Old??  This is not documented. */
end_comment

begin_undef
undef|#
directive|undef
name|MD_EXEC_PREFIX
end_undef

begin_comment
comment|/* We don't want one. */
end_comment

begin_define
define|#
directive|define
name|STANDARD_EXEC_PREFIX
value|PREFIX"/libexec/"
end_define

begin_comment
comment|/* Under FreeBSD, the normal location of the various *crt*.o files is the    /usr/lib directory.  */
end_comment

begin_undef
undef|#
directive|undef
name|MD_STARTFILE_PREFIX
end_undef

begin_comment
comment|/* We don't need one for now. */
end_comment

begin_define
define|#
directive|define
name|STANDARD_STARTFILE_PREFIX
value|PREFIX"/lib/"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CROSS_COMPILE
end_ifdef

begin_define
define|#
directive|define
name|CROSS_STARTFILE_PREFIX
value|PREFIX"/lib/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For the native system compiler, we actually build libgcc in a profiled    version.  So we should use it with -pg.  */
end_comment

begin_define
define|#
directive|define
name|LIBGCC_SPEC
value|"%{!pg: -lgcc} %{pg: -lgcc_p}"
end_define

begin_comment
comment|/* FreeBSD is 4.4BSD derived */
end_comment

begin_define
define|#
directive|define
name|bsd4_4
end_define

end_unit

