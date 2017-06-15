begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_INCLUDES_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_INCLUDES_H
end_define

begin_comment
comment|/*  * jemalloc can conceptually be broken into components (arena, tcache, etc.),  * but there are circular dependencies that cannot be broken without  * substantial performance degradation.  *  * Historically, we dealt with this by each header into four sections (types,  * structs, externs, and inlines), and included each header file multiple times  * in this file, picking out the portion we want on each pass using the  * following #defines:  *   JEMALLOC_H_TYPES   : Preprocessor-defined constants and psuedo-opaque data  *                        types.  *   JEMALLOC_H_STRUCTS : Data structures.  *   JEMALLOC_H_EXTERNS : Extern data declarations and function prototypes.  *   JEMALLOC_H_INLINES : Inline functions.  *  * We're moving toward a world in which the dependencies are explicit; each file  * will #include the headers it depends on (rather than relying on them being  * implicitly available via this file including every header file in the  * project).  *  * We're now in an intermediate state: we've broken up the header files to avoid  * having to include each one multiple times, but have not yet moved the  * dependency information into the header files (i.e. we still rely on the  * ordering in this file to ensure all a header's dependencies are available in  * its translation unit).  Each component is now broken up into multiple header  * files, corresponding to the sections above (e.g. instead of "foo.h", we now  * have "foo_types.h", "foo_structs.h", "foo_externs.h", "foo_inlines.h").  *  * Those files which have been converted to explicitly include their  * inter-component dependencies are now in the initial HERMETIC HEADERS  * section.  All headers may still rely on jemalloc_preamble.h (which, by fiat,  * must be included first in every translation unit) for system headers and  * global jemalloc definitions, however.  */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_comment
comment|/* TYPES */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"jemalloc/internal/extent_types.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/base_types.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/arena_types.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/tcache_types.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/prof_types.h"
end_include

begin_comment
comment|/******************************************************************************/
end_comment

begin_comment
comment|/* STRUCTS */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"jemalloc/internal/arena_structs_a.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/extent_structs.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/base_structs.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/prof_structs.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/arena_structs_b.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/tcache_structs.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/background_thread_structs.h"
end_include

begin_comment
comment|/******************************************************************************/
end_comment

begin_comment
comment|/* EXTERNS */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"jemalloc/internal/jemalloc_internal_externs.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/extent_externs.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/base_externs.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/arena_externs.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/large_externs.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/tcache_externs.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/prof_externs.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/background_thread_externs.h"
end_include

begin_comment
comment|/******************************************************************************/
end_comment

begin_comment
comment|/* INLINES */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"jemalloc/internal/jemalloc_internal_inlines_a.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/base_inlines.h"
end_include

begin_comment
comment|/*  * Include portions of arena code interleaved with tcache code in order to  * resolve circular dependencies.  */
end_comment

begin_include
include|#
directive|include
file|"jemalloc/internal/prof_inlines_a.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/arena_inlines_a.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/extent_inlines.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/jemalloc_internal_inlines_b.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/tcache_inlines.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/arena_inlines_b.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/jemalloc_internal_inlines_c.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/prof_inlines_b.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/background_thread_inlines.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_INCLUDES_H */
end_comment

end_unit

