begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_SKEIN_DEBUG_H_
end_ifndef

begin_define
define|#
directive|define
name|_SKEIN_DEBUG_H_
end_define

begin_comment
comment|/*********************************************************************** ** ** Interface definitions for Skein hashing debug output. ** ** Source code author: Doug Whiting, 2008. ** ** This algorithm and source code is released to the public domain. ** ************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SKEIN_DEBUG
end_ifdef

begin_comment
comment|/* callout functions used inside Skein code */
end_comment

begin_function_decl
name|void
name|Skein_Show_Block
parameter_list|(
name|uint_t
name|bits
parameter_list|,
specifier|const
name|Skein_Ctxt_Hdr_t
modifier|*
name|h
parameter_list|,
specifier|const
name|u64b_t
modifier|*
name|X
parameter_list|,
specifier|const
name|u08b_t
modifier|*
name|blkPtr
parameter_list|,
specifier|const
name|u64b_t
modifier|*
name|wPtr
parameter_list|,
specifier|const
name|u64b_t
modifier|*
name|ksPtr
parameter_list|,
specifier|const
name|u64b_t
modifier|*
name|tsPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Skein_Show_Round
parameter_list|(
name|uint_t
name|bits
parameter_list|,
specifier|const
name|Skein_Ctxt_Hdr_t
modifier|*
name|h
parameter_list|,
name|size_t
name|r
parameter_list|,
specifier|const
name|u64b_t
modifier|*
name|X
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Skein_Show_R_Ptr
parameter_list|(
name|uint_t
name|bits
parameter_list|,
specifier|const
name|Skein_Ctxt_Hdr_t
modifier|*
name|h
parameter_list|,
name|size_t
name|r
parameter_list|,
specifier|const
name|u64b_t
modifier|*
name|X_ptr
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Skein_Show_Final
parameter_list|(
name|uint_t
name|bits
parameter_list|,
specifier|const
name|Skein_Ctxt_Hdr_t
modifier|*
name|h
parameter_list|,
name|size_t
name|cnt
parameter_list|,
specifier|const
name|u08b_t
modifier|*
name|outPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Skein_Show_Key
parameter_list|(
name|uint_t
name|bits
parameter_list|,
specifier|const
name|Skein_Ctxt_Hdr_t
modifier|*
name|h
parameter_list|,
specifier|const
name|u08b_t
modifier|*
name|key
parameter_list|,
name|size_t
name|keyBytes
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|uint_t
name|skein_DebugFlag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flags to control debug output (0 --> none) */
end_comment

begin_define
define|#
directive|define
name|SKEIN_RND_SPECIAL
value|(1000u)
end_define

begin_define
define|#
directive|define
name|SKEIN_RND_KEY_INITIAL
value|(SKEIN_RND_SPECIAL+0u)
end_define

begin_define
define|#
directive|define
name|SKEIN_RND_KEY_INJECT
value|(SKEIN_RND_SPECIAL+1u)
end_define

begin_define
define|#
directive|define
name|SKEIN_RND_FEED_FWD
value|(SKEIN_RND_SPECIAL+2u)
end_define

begin_comment
comment|/* flag bits:  skein_DebugFlag */
end_comment

begin_define
define|#
directive|define
name|SKEIN_DEBUG_KEY
value|(1u<< 1)
end_define

begin_comment
comment|/* show MAC key */
end_comment

begin_define
define|#
directive|define
name|SKEIN_DEBUG_CONFIG
value|(1u<< 2)
end_define

begin_comment
comment|/* show config block processing */
end_comment

begin_define
define|#
directive|define
name|SKEIN_DEBUG_STATE
value|(1u<< 3)
end_define

begin_comment
comment|/* show input state during Show_Block() */
end_comment

begin_define
define|#
directive|define
name|SKEIN_DEBUG_TWEAK
value|(1u<< 4)
end_define

begin_comment
comment|/* show input state during Show_Block() */
end_comment

begin_define
define|#
directive|define
name|SKEIN_DEBUG_KEYSCHED
value|(1u<< 5)
end_define

begin_comment
comment|/* show expanded key schedule */
end_comment

begin_define
define|#
directive|define
name|SKEIN_DEBUG_INPUT_64
value|(1u<< 6)
end_define

begin_comment
comment|/* show input block as 64-bit words */
end_comment

begin_define
define|#
directive|define
name|SKEIN_DEBUG_INPUT_08
value|(1u<< 7)
end_define

begin_comment
comment|/* show input block as  8-bit bytes */
end_comment

begin_define
define|#
directive|define
name|SKEIN_DEBUG_INJECT
value|(1u<< 8)
end_define

begin_comment
comment|/* show state after key injection& feedforward points */
end_comment

begin_define
define|#
directive|define
name|SKEIN_DEBUG_ROUNDS
value|(1u<< 9)
end_define

begin_comment
comment|/* show state after all rounds */
end_comment

begin_define
define|#
directive|define
name|SKEIN_DEBUG_FINAL
value|(1u<<10)
end_define

begin_comment
comment|/* show final output of Skein */
end_comment

begin_define
define|#
directive|define
name|SKEIN_DEBUG_HDR
value|(1u<<11)
end_define

begin_comment
comment|/* show block header */
end_comment

begin_define
define|#
directive|define
name|SKEIN_DEBUG_THREEFISH
value|(1u<<12)
end_define

begin_comment
comment|/* use Threefish name instead of Skein */
end_comment

begin_define
define|#
directive|define
name|SKEIN_DEBUG_PERMUTE
value|(1u<<13)
end_define

begin_comment
comment|/* use word permutations */
end_comment

begin_define
define|#
directive|define
name|SKEIN_DEBUG_ALL
value|((~0u)& ~(SKEIN_DEBUG_THREEFISH | SKEIN_DEBUG_PERMUTE))
end_define

begin_define
define|#
directive|define
name|THREEFISH_DEBUG_ALL
value|(SKEIN_DEBUG_ALL | SKEIN_DEBUG_THREEFISH)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  SKEIN_DEBUG    */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SKEIN_DEBUG_H_ */
end_comment

end_unit

