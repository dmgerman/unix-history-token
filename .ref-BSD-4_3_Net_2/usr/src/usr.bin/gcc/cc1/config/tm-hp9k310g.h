begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  HP-UX 68000/68020 version.    Use this file if GCC is supposed to work with the GNU assembler,    GNU linker and GNU debugger using DBX debugging information.    (In other words, much of HPUX has been cast aside.)  */
end_comment

begin_comment
comment|/* This wants DBX format.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_define
define|#
directive|define
name|USE_GAS
end_define

begin_include
include|#
directive|include
file|"tm-hp9k310.h"
end_include

end_unit

