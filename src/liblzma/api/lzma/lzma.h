begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * \file        lzma/lzma.h  * \brief       LZMA1 and LZMA2 filters  */
end_comment

begin_comment
comment|/*  * Author: Lasse Collin  *  * This file has been put into the public domain.  * You can do whatever you want with this file.  *  * See ../lzma.h for information about liblzma as a whole.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LZMA_H_INTERNAL
end_ifndef

begin_error
error|#
directive|error
error|Never include this file directly. Use<lzma.h> instead.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**  * \brief       LZMA1 Filter ID  *  * LZMA1 is the very same thing as what was called just LZMA in LZMA Utils,  * 7-Zip, and LZMA SDK. It's called LZMA1 here to prevent developers from  * accidentally using LZMA when they actually want LZMA2.  *  * LZMA1 shouldn't be used for new applications unless you _really_ know  * what you are doing. LZMA2 is almost always a better choice.  */
end_comment

begin_define
define|#
directive|define
name|LZMA_FILTER_LZMA1
value|LZMA_VLI_C(0x4000000000000001)
end_define

begin_comment
comment|/**  * \brief       LZMA2 Filter ID  *  * Usually you want this instead of LZMA1. Compared to LZMA1, LZMA2 adds  * support for LZMA_SYNC_FLUSH, uncompressed chunks (smaller expansion  * when trying to compress uncompressible data), possibility to change  * lc/lp/pb in the middle of encoding, and some other internal improvements.  */
end_comment

begin_define
define|#
directive|define
name|LZMA_FILTER_LZMA2
value|LZMA_VLI_C(0x21)
end_define

begin_comment
comment|/**  * \brief       Match finders  *  * Match finder has major effect on both speed and compression ratio.  * Usually hash chains are faster than binary trees.  *  * The memory usage formulas are only rough estimates, which are closest to  * reality when dict_size is a power of two. The formulas are  more complex  * in reality, and can also change a little between liblzma versions. Use  * lzma_raw_encoder_memusage() to get more accurate estimate of memory usage.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|LZMA_MF_HC3
init|=
literal|0x03
block|,
comment|/**< 		 * \brief       Hash Chain with 2- and 3-byte hashing 		 * 		 * Minimum nice_len: 3 		 * 		 * Memory usage: 		 *  - dict_size<= 16 MiB: dict_size * 7.5 		 *  - dict_size> 16 MiB: dict_size * 5.5 + 64 MiB 		 */
name|LZMA_MF_HC4
init|=
literal|0x04
block|,
comment|/**< 		 * \brief       Hash Chain with 2-, 3-, and 4-byte hashing 		 * 		 * Minimum nice_len: 4 		 * 		 * Memory usage: 		 *  - dict_size<= 32 MiB: dict_size * 7.5 		 *  - dict_size> 32 MiB: dict_size * 6.5 		 */
name|LZMA_MF_BT2
init|=
literal|0x12
block|,
comment|/**< 		 * \brief       Binary Tree with 2-byte hashing 		 * 		 * Minimum nice_len: 2 		 * 		 * Memory usage: dict_size * 9.5 		 */
name|LZMA_MF_BT3
init|=
literal|0x13
block|,
comment|/**< 		 * \brief       Binary Tree with 2- and 3-byte hashing 		 * 		 * Minimum nice_len: 3 		 * 		 * Memory usage: 		 *  - dict_size<= 16 MiB: dict_size * 11.5 		 *  - dict_size> 16 MiB: dict_size * 9.5 + 64 MiB 		 */
name|LZMA_MF_BT4
init|=
literal|0x14
comment|/**< 		 * \brief       Binary Tree with 2-, 3-, and 4-byte hashing 		 * 		 * Minimum nice_len: 4 		 * 		 * Memory usage: 		 *  - dict_size<= 32 MiB: dict_size * 11.5 		 *  - dict_size> 32 MiB: dict_size * 10.5 		 */
block|}
name|lzma_match_finder
typedef|;
end_typedef

begin_comment
comment|/**  * \brief       Test if given match finder is supported  *  * Return true if the given match finder is supported by this liblzma build.  * Otherwise false is returned. It is safe to call this with a value that  * isn't listed in lzma_match_finder enumeration; the return value will be  * false.  *  * There is no way to list which match finders are available in this  * particular liblzma version and build. It would be useless, because  * a new match finder, which the application developer wasn't aware,  * could require giving additional options to the encoder that the older  * match finders don't need.  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_bool
end_extern

begin_macro
unit|)
name|lzma_mf_is_supported
argument_list|(
argument|lzma_match_finder match_finder
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Compression modes  *  * This selects the function used to analyze the data produced by the match  * finder.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|LZMA_MODE_FAST
init|=
literal|1
block|,
comment|/**< 		 * \brief       Fast compression 		 * 		 * Fast mode is usually at its best when combined with 		 * a hash chain match finder. 		 */
name|LZMA_MODE_NORMAL
init|=
literal|2
comment|/**< 		 * \brief       Normal compression 		 * 		 * This is usually notably slower than fast mode. Use this 		 * together with binary tree match finders to expose the 		 * full potential of the LZMA1 or LZMA2 encoder. 		 */
block|}
name|lzma_mode
typedef|;
end_typedef

begin_comment
comment|/**  * \brief       Test if given compression mode is supported  *  * Return true if the given compression mode is supported by this liblzma  * build. Otherwise false is returned. It is safe to call this with a value  * that isn't listed in lzma_mode enumeration; the return value will be false.  *  * There is no way to list which modes are available in this particular  * liblzma version and build. It would be useless, because a new compression  * mode, which the application developer wasn't aware, could require giving  * additional options to the encoder that the older modes don't need.  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_bool
end_extern

begin_macro
unit|)
name|lzma_mode_is_supported
argument_list|(
argument|lzma_mode mode
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Options specific to the LZMA1 and LZMA2 filters  *  * Since LZMA1 and LZMA2 share most of the code, it's simplest to share  * the options structure too. For encoding, all but the reserved variables  * need to be initialized unless specifically mentioned otherwise.  *  * For raw decoding, both LZMA1 and LZMA2 need dict_size, preset_dict, and  * preset_dict_size (if preset_dict != NULL). LZMA1 needs also lc, lp, and pb.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/** 	 * \brief       Dictionary size in bytes 	 * 	 * Dictionary size indicates how many bytes of the recently processed 	 * uncompressed data is kept in memory. One method to reduce size of 	 * the uncompressed data is to store distance-length pairs, which 	 * indicate what data to repeat from the dictionary buffer. Thus, 	 * the bigger the dictionary, the better the compression ratio 	 * usually is. 	 * 	 * Maximum size of the dictionary depends on multiple things: 	 *  - Memory usage limit 	 *  - Available address space (not a problem on 64-bit systems) 	 *  - Selected match finder (encoder only) 	 * 	 * Currently the maximum dictionary size for encoding is 1.5 GiB 	 * (i.e. (UINT32_C(1)<< 30) + (UINT32_C(1)<< 29)) even on 64-bit 	 * systems for certain match finder implementation reasons. In the 	 * future, there may be match finders that support bigger 	 * dictionaries. 	 * 	 * Decoder already supports dictionaries up to 4 GiB - 1 B (i.e. 	 * UINT32_MAX), so increasing the maximum dictionary size of the 	 * encoder won't cause problems for old decoders. 	 * 	 * Because extremely small dictionaries sizes would have unneeded 	 * overhead in the decoder, the minimum dictionary size is 4096 bytes. 	 * 	 * \note        When decoding, too big dictionary does no other harm 	 *              than wasting memory. 	 */
name|uint32_t
name|dict_size
decl_stmt|;
define|#
directive|define
name|LZMA_DICT_SIZE_MIN
value|UINT32_C(4096)
define|#
directive|define
name|LZMA_DICT_SIZE_DEFAULT
value|(UINT32_C(1)<< 23)
comment|/** 	 * \brief       Pointer to an initial dictionary 	 * 	 * It is possible to initialize the LZ77 history window using 	 * a preset dictionary. It is useful when compressing many 	 * similar, relatively small chunks of data independently from 	 * each other. The preset dictionary should contain typical 	 * strings that occur in the files being compressed. The most 	 * probable strings should be near the end of the preset dictionary. 	 * 	 * This feature should be used only in special situations. For 	 * now, it works correctly only with raw encoding and decoding. 	 * Currently none of the container formats supported by 	 * liblzma allow preset dictionary when decoding, thus if 	 * you create a .xz or .lzma file with preset dictionary, it 	 * cannot be decoded with the regular decoder functions. In the 	 * future, the .xz format will likely get support for preset 	 * dictionary though. 	 */
specifier|const
name|uint8_t
modifier|*
name|preset_dict
decl_stmt|;
comment|/** 	 * \brief       Size of the preset dictionary 	 * 	 * Specifies the size of the preset dictionary. If the size is 	 * bigger than dict_size, only the last dict_size bytes are 	 * processed. 	 * 	 * This variable is read only when preset_dict is not NULL. 	 * If preset_dict is not NULL but preset_dict_size is zero, 	 * no preset dictionary is used (identical to only setting 	 * preset_dict to NULL). 	 */
name|uint32_t
name|preset_dict_size
decl_stmt|;
comment|/** 	 * \brief       Number of literal context bits 	 * 	 * How many of the highest bits of the previous uncompressed 	 * eight-bit byte (also known as `literal') are taken into 	 * account when predicting the bits of the next literal. 	 * 	 * \todo        Example 	 * 	 * There is a limit that applies to literal context bits and literal 	 * position bits together: lc + lp<= 4. Without this limit the 	 * decoding could become very slow, which could have security related 	 * results in some cases like email servers doing virus scanning. 	 * This limit also simplifies the internal implementation in liblzma. 	 * 	 * There may be LZMA1 streams that have lc + lp> 4 (maximum possible 	 * lc would be 8). It is not possible to decode such streams with 	 * liblzma. 	 */
name|uint32_t
name|lc
decl_stmt|;
define|#
directive|define
name|LZMA_LCLP_MIN
value|0
define|#
directive|define
name|LZMA_LCLP_MAX
value|4
define|#
directive|define
name|LZMA_LC_DEFAULT
value|3
comment|/** 	 * \brief       Number of literal position bits 	 * 	 * How many of the lowest bits of the current position (number 	 * of bytes from the beginning of the uncompressed data) in the 	 * uncompressed data is taken into account when predicting the 	 * bits of the next literal (a single eight-bit byte). 	 * 	 * \todo        Example 	 */
name|uint32_t
name|lp
decl_stmt|;
define|#
directive|define
name|LZMA_LP_DEFAULT
value|0
comment|/** 	 * \brief       Number of position bits 	 * 	 * How many of the lowest bits of the current position in the 	 * uncompressed data is taken into account when estimating 	 * probabilities of matches. A match is a sequence of bytes for 	 * which a matching sequence is found from the dictionary and 	 * thus can be stored as distance-length pair. 	 * 	 * Example: If most of the matches occur at byte positions of 	 * 8 * n + 3, that is, 3, 11, 19, ... set pb to 3, because 2**3 == 8. 	 */
name|uint32_t
name|pb
decl_stmt|;
define|#
directive|define
name|LZMA_PB_MIN
value|0
define|#
directive|define
name|LZMA_PB_MAX
value|4
define|#
directive|define
name|LZMA_PB_DEFAULT
value|2
comment|/** Compression mode */
name|lzma_mode
name|mode
decl_stmt|;
comment|/** 	 * \brief       Nice length of a match 	 * 	 * This determines how many bytes the encoder compares from the match 	 * candidates when looking for the best match. Once a match of at 	 * least nice_len bytes long is found, the encoder stops looking for 	 * better candidates and encodes the match. (Naturally, if the found 	 * match is actually longer than nice_len, the actual length is 	 * encoded; it's not truncated to nice_len.) 	 * 	 * Bigger values usually increase the compression ratio and 	 * compression time. For most files, 32 to 128 is a good value, 	 * which gives very good compression ratio at good speed. 	 * 	 * The exact minimum value depends on the match finder. The maximum 	 * is 273, which is the maximum length of a match that LZMA1 and 	 * LZMA2 can encode. 	 */
name|uint32_t
name|nice_len
decl_stmt|;
comment|/** Match finder ID */
name|lzma_match_finder
name|mf
decl_stmt|;
comment|/** 	 * \brief       Maximum search depth in the match finder 	 * 	 * For every input byte, match finder searches through the hash chain 	 * or binary tree in a loop, each iteration going one step deeper in 	 * the chain or tree. The searching stops if 	 *  - a match of at least nice_len bytes long is found; 	 *  - all match candidates from the hash chain or binary tree have 	 *    been checked; or 	 *  - maximum search depth is reached. 	 * 	 * Maximum search depth is needed to prevent the match finder from 	 * wasting too much time in case there are lots of short match 	 * candidates. On the other hand, stopping the search before all 	 * candidates have been checked can reduce compression ratio. 	 * 	 * Setting depth to zero tells liblzma to use an automatic default 	 * value, that depends on the selected match finder and nice_len. 	 * The default is in the range [10, 200] or so (it may vary between 	 * liblzma versions). 	 * 	 * Using a bigger depth value than the default can increase 	 * compression ratio in some cases. There is no strict maximum value, 	 * but high values (thousands or millions) should be used with care: 	 * the encoder could remain fast enough with typical input, but 	 * malicious input could cause the match finder to slow down 	 * dramatically, possibly creating a denial of service attack. 	 */
name|uint32_t
name|depth
decl_stmt|;
comment|/* 	 * Reserved space to allow possible future extensions without 	 * breaking the ABI. You should not touch these, because the names 	 * of these variables may change. These are and will never be used 	 * with the currently supported options, so it is safe to leave these 	 * uninitialized. 	 */
name|void
modifier|*
name|reserved_ptr1
decl_stmt|;
name|void
modifier|*
name|reserved_ptr2
decl_stmt|;
name|uint32_t
name|reserved_int1
decl_stmt|;
name|uint32_t
name|reserved_int2
decl_stmt|;
name|uint32_t
name|reserved_int3
decl_stmt|;
name|uint32_t
name|reserved_int4
decl_stmt|;
name|uint32_t
name|reserved_int5
decl_stmt|;
name|uint32_t
name|reserved_int6
decl_stmt|;
name|uint32_t
name|reserved_int7
decl_stmt|;
name|uint32_t
name|reserved_int8
decl_stmt|;
name|lzma_reserved_enum
name|reserved_enum1
decl_stmt|;
name|lzma_reserved_enum
name|reserved_enum2
decl_stmt|;
name|lzma_reserved_enum
name|reserved_enum3
decl_stmt|;
name|lzma_reserved_enum
name|reserved_enum4
decl_stmt|;
block|}
name|lzma_options_lzma
typedef|;
end_typedef

begin_comment
comment|/**  * \brief       Set a compression preset to lzma_options_lzma structure  *  * 0 is the fastest and 9 is the slowest. These match the switches -0 .. -9  * of the xz command line tool. In addition, it is possible to bitwise-or  * flags to the preset. Currently only LZMA_PRESET_EXTREME is supported.  * The flags are defined in container.h, because the flags are used also  * with lzma_easy_encoder().  *  * The preset values are subject to changes between liblzma versions.  *  * This function is available only if LZMA1 or LZMA2 encoder has been enabled  * when building liblzma.  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_bool
end_extern

begin_macro
unit|)
name|lzma_lzma_preset
argument_list|(
argument|lzma_options_lzma *options
argument_list|,
argument|uint32_t preset
argument_list|)
end_macro

begin_expr_stmt
name|lzma_nothrow
expr_stmt|;
end_expr_stmt

end_unit

