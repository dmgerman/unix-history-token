begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_AHS_API_H_
end_ifndef

begin_define
define|#
directive|define
name|_AHS_API_H_
end_define

begin_comment
comment|/*********************************************************************** ** ** Interface declarations of the AHS API using the Skein hash function. ** ** Source code author: Doug Whiting, 2008. ** ** This algorithm and source code is released to the public domain. **  ************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"skein.h"
end_include

begin_typedef
typedef|typedef
enum|enum
block|{
name|SUCCESS
init|=
name|SKEIN_SUCCESS
block|,
name|FAIL
init|=
name|SKEIN_FAIL
block|,
name|BAD_HASHLEN
init|=
name|SKEIN_BAD_HASHLEN
block|}
name|HashReturn
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|size_t
name|DataLength
typedef|;
end_typedef

begin_comment
comment|/* bit count  type */
end_comment

begin_typedef
typedef|typedef
name|u08b_t
name|BitSequence
typedef|;
end_typedef

begin_comment
comment|/* bit stream type */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint_t
name|statebits
decl_stmt|;
comment|/* 256, 512, or 1024 */
union|union
block|{
name|Skein_Ctxt_Hdr_t
name|h
decl_stmt|;
comment|/* common header "overlay" */
name|Skein_256_Ctxt_t
name|ctx_256
decl_stmt|;
name|Skein_512_Ctxt_t
name|ctx_512
decl_stmt|;
name|Skein1024_Ctxt_t
name|ctx1024
decl_stmt|;
block|}
name|u
union|;
block|}
name|hashState
typedef|;
end_typedef

begin_comment
comment|/* "incremental" hashing API */
end_comment

begin_function_decl
name|HashReturn
name|Init
parameter_list|(
name|hashState
modifier|*
name|state
parameter_list|,
name|int
name|hashbitlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|HashReturn
name|Update
parameter_list|(
name|hashState
modifier|*
name|state
parameter_list|,
specifier|const
name|BitSequence
modifier|*
name|data
parameter_list|,
name|DataLength
name|databitlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|HashReturn
name|Final
parameter_list|(
name|hashState
modifier|*
name|state
parameter_list|,
name|BitSequence
modifier|*
name|hashval
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* "all-in-one" call */
end_comment

begin_function_decl
name|HashReturn
name|Hash
parameter_list|(
name|int
name|hashbitlen
parameter_list|,
specifier|const
name|BitSequence
modifier|*
name|data
parameter_list|,
name|DataLength
name|databitlen
parameter_list|,
name|BitSequence
modifier|*
name|hashval
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ** Re-define the compile-time constants below to change the selection ** of the Skein state size in the Init() function in SHA3api_ref.c. ** ** That is, the NIST API does not allow for explicit selection of the ** Skein block size, so it must be done implicitly in the Init() function. ** The selection is controlled by these constants. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SKEIN_256_NIST_MAX_HASHBITS
end_ifndef

begin_define
define|#
directive|define
name|SKEIN_256_NIST_MAX_HASHBITS
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SKEIN_512_NIST_MAX_HASHBITS
end_ifndef

begin_define
define|#
directive|define
name|SKEIN_512_NIST_MAX_HASHBITS
value|(512)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifdef _AHS_API_H_ */
end_comment

end_unit

