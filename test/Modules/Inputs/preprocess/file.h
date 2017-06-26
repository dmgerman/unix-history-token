begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"other.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|FILE_H
end_ifndef

begin_define
define|#
directive|define
name|FILE_H
end_define

begin_struct_decl
struct_decl|struct
name|__FILE
struct_decl|;
end_struct_decl

begin_include
include|#
directive|include
file|"fwd.h"
end_include

begin_typedef
typedef|typedef
name|struct
name|__FILE
name|FILE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|foo
name|bar
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

