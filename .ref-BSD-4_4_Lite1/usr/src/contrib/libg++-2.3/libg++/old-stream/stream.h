begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ostream.h and istream.h now separately includable */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_stream_h
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
name|_stream_h
value|1
end_define

begin_include
include|#
directive|include
file|<ostream.h>
end_include

begin_include
include|#
directive|include
file|<istream.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

