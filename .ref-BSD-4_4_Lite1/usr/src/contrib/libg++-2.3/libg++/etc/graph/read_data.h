begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|// READ_DATA reads ascii (or binary) data from an istream (or File) of
end_comment

begin_comment
comment|// coordinates and labels.  It passes back the array of points (x, y,
end_comment

begin_comment
comment|// and label) containing the data.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|read_data_h
end_ifndef

begin_define
define|#
directive|define
name|read_data_h
value|1
end_define

begin_include
include|#
directive|include
file|<stream.h>
end_include

begin_include
include|#
directive|include
file|<String.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|"pXPlex.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HUGE
end_ifdef

begin_undef
undef|#
directive|undef
name|HUGE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HUGE
value|1e37
end_define

begin_define
define|#
directive|define
name|sp
value|<<" "<<
end_define

begin_define
define|#
directive|define
name|nl
value|<<"\n"
end_define

begin_comment
comment|// data_type value indicates the type of data present in the input files.
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ASCII
block|,
name|DOUBLE
block|,
name|INT
block|}
name|data_type
typedef|;
end_typedef

begin_comment
comment|// read ascii binary data from a file
end_comment

begin_function_decl
name|void
name|read_data
parameter_list|(
name|istream
modifier|&
name|in
parameter_list|,
name|char
modifier|*
name|in_filename
parameter_list|,
name|pointXPlex
modifier|&
name|pplex
parameter_list|,
name|int
name|auto_abscissa
parameter_list|,
name|double
name|x_start
parameter_list|,
name|double
name|delta_x
parameter_list|,
name|int
modifier|&
name|symbol_number
parameter_list|,
name|data_type
name|input_data
parameter_list|,
name|int
name|switch_symbols
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

