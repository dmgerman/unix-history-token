begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_FAKE_SYS_MMAN_H
end_ifndef

begin_define
define|#
directive|define
name|_FAKE_SYS_MMAN_H
value|1
end_define

begin_define
define|#
directive|define
name|mmap
value|mmap_hack
end_define

begin_comment
comment|/* fake mmap() using malloc() + read() */
end_comment

begin_define
define|#
directive|define
name|munmap
value|munmap_hack
end_define

begin_comment
comment|/* fake munmap() using free() */
end_comment

begin_define
define|#
directive|define
name|PROT_READ
value|0x1
end_define

begin_comment
comment|/* pages can be read */
end_comment

begin_define
define|#
directive|define
name|PROT_WRITE
value|0x2
end_define

begin_comment
comment|/* pages can be written */
end_comment

begin_define
define|#
directive|define
name|PROT_EXEC
value|0x4
end_define

begin_comment
comment|/* pages can be executed */
end_comment

begin_define
define|#
directive|define
name|MAP_SHARED
value|1
end_define

begin_comment
comment|/* share changes */
end_comment

begin_define
define|#
directive|define
name|MAP_PRIVATE
value|2
end_define

begin_comment
comment|/* changes are private */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_function_decl
specifier|extern
name|void
modifier|*
name|mmap
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|munmap
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
modifier|*
name|mmap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|munmap
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FAKE_SYS_MMAN_H */
end_comment

end_unit

