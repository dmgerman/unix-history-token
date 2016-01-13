begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This module only exists to make local decl IDs and global decl IDs different.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DUMMY_H
end_ifndef

begin_define
define|#
directive|define
name|DUMMY_H
end_define

begin_struct
struct|struct
name|Dummy
block|{}
decl|extern
modifier|*
name|dummy1
struct|,
modifier|*
name|dummy2
struct|,
modifier|*
name|dummy3
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

