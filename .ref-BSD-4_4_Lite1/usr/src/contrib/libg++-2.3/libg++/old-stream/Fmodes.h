begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_Fmodes_h
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|interface
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_Fmodes_h
value|1
end_define

begin_enum
enum|enum
name|io_mode
comment|// known unix file IO modes
block|{
name|io_readonly
init|=
literal|0
block|,
name|io_writeonly
init|=
literal|1
block|,
name|io_readwrite
init|=
literal|2
block|,
name|io_appendonly
init|=
literal|3
block|,
name|io_append
init|=
literal|4
block|,
comment|// append, plus allow reads
block|}
enum|;
end_enum

begin_enum
enum|enum
name|access_mode
comment|// ways to open a file
block|{
name|a_createonly
init|=
literal|0
block|,
comment|// create, fail if file exists
name|a_create
init|=
literal|1
block|,
comment|// create if doesn't exist, else truncate
name|a_useonly
init|=
literal|2
block|,
comment|// use (no truncate)  fail if doesn't exist
name|a_use
init|=
literal|3
block|,
comment|// use (no truncate), create if doesn't exist
block|}
enum|;
end_enum

begin_enum
enum|enum
name|state_value
comment|// File states
block|{
name|_good
init|=
literal|0
block|,
comment|// all is well
name|_eof
init|=
literal|1
block|,
comment|// at eof
name|_fail
init|=
literal|2
block|,
comment|// logical or physical IO error
name|_bad
init|=
literal|4
comment|// unopened/corrupted
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

end_unit

