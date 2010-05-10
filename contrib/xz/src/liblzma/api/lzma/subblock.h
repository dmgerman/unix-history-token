begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * \file        lzma/subblock.h  * \brief       Subblock filter  */
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
comment|/**  * \brief       Filter ID  *  * Filter ID of the Subblock filter. This is used as lzma_filter.id.  */
end_comment

begin_define
define|#
directive|define
name|LZMA_FILTER_SUBBLOCK
value|LZMA_VLI_C(0x01)
end_define

begin_comment
comment|/**  * \brief       Subfilter mode  *  * See lzma_options_subblock.subfilter_mode for details.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|LZMA_SUBFILTER_NONE
block|,
comment|/**< 		 * No Subfilter is in use. 		 */
name|LZMA_SUBFILTER_SET
block|,
comment|/**< 		 * New Subfilter has been requested to be initialized. 		 */
name|LZMA_SUBFILTER_RUN
block|,
comment|/**< 		 * Subfilter is active. 		 */
name|LZMA_SUBFILTER_FINISH
comment|/**< 		 * Subfilter has been requested to be finished. 		 */
block|}
name|lzma_subfilter_mode
typedef|;
end_typedef

begin_comment
comment|/**  * \brief       Options for the Subblock filter  *  * Specifying options for the Subblock filter is optional: if the pointer  * options is NULL, no subfilters are allowed and the default value is used  * for subblock_data_size.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Options for encoder and decoder */
comment|/** 	 * \brief       Allowing subfilters 	 * 	 * If this true, subfilters are allowed. 	 * 	 * In the encoder, if this is set to false, subfilter_mode and 	 * subfilter_options are completely ignored. 	 */
name|lzma_bool
name|allow_subfilters
decl_stmt|;
comment|/* Options for encoder only */
comment|/** 	 * \brief       Alignment 	 * 	 * The Subblock filter encapsulates the input data into Subblocks. 	 * Each Subblock has a header which takes a few bytes of space. 	 * When the output of the Subblock encoder is fed to another filter 	 * that takes advantage of the alignment of the input data (e.g. LZMA), 	 * the Subblock filter can add padding to keep the actual data parts 	 * in the Subblocks aligned correctly. 	 * 	 * The alignment should be a positive integer. Subblock filter will 	 * add enough padding between Subblocks so that this is true for 	 * every payload byte: 	 * input_offset % alignment == output_offset % alignment 	 * 	 * The Subblock filter assumes that the first output byte will be 	 * written to a position in the output stream that is properly 	 * aligned. This requirement is automatically met when the start 	 * offset of the Stream or Block is correctly told to Block or 	 * Stream encoder. 	 */
name|uint32_t
name|alignment
decl_stmt|;
define|#
directive|define
name|LZMA_SUBBLOCK_ALIGNMENT_MIN
value|1
define|#
directive|define
name|LZMA_SUBBLOCK_ALIGNMENT_MAX
value|32
define|#
directive|define
name|LZMA_SUBBLOCK_ALIGNMENT_DEFAULT
value|4
comment|/** 	 * \brief       Size of the Subblock Data part of each Subblock 	 * 	 * This value is re-read every time a new Subblock is started. 	 * 	 * Bigger values 	 *   - save a few bytes of space; 	 *   - increase latency in the encoder (but no effect for decoding); 	 *   - decrease memory locality (increased cache pollution) in the 	 *     encoder (no effect in decoding). 	 */
name|uint32_t
name|subblock_data_size
decl_stmt|;
define|#
directive|define
name|LZMA_SUBBLOCK_DATA_SIZE_MIN
value|1
define|#
directive|define
name|LZMA_SUBBLOCK_DATA_SIZE_MAX
value|(UINT32_C(1)<< 28)
define|#
directive|define
name|LZMA_SUBBLOCK_DATA_SIZE_DEFAULT
value|4096
comment|/** 	 * \brief       Run-length encoder remote control 	 * 	 * The Subblock filter has an internal run-length encoder (RLE). It 	 * can be useful when the data includes byte sequences that repeat 	 * very many times. The RLE can be used also when a Subfilter is 	 * in use; the RLE will be applied to the output of the Subfilter. 	 * 	 * Note that in contrast to traditional RLE, this RLE is intended to 	 * be used only when there's a lot of data to be repeated. If the 	 * input data has e.g. 500 bytes of NULs now and then, this RLE 	 * is probably useless, because plain LZMA should provide better 	 * results. 	 * 	 * Due to above reasons, it was decided to keep the implementation 	 * of the RLE very simple. When the rle variable is non-zero, it 	 * subblock_data_size must be a multiple of rle. Once the Subblock 	 * encoder has got subblock_data_size bytes of input, it will check 	 * if the whole buffer of the last subblock_data_size can be 	 * represented with repeats of chunks having size of rle bytes. 	 * 	 * If there are consecutive identical buffers of subblock_data_size 	 * bytes, they will be encoded using a single repeat entry if 	 * possible. 	 * 	 * If need arises, more advanced RLE can be implemented later 	 * without breaking API or ABI. 	 */
name|uint32_t
name|rle
decl_stmt|;
define|#
directive|define
name|LZMA_SUBBLOCK_RLE_OFF
value|0
define|#
directive|define
name|LZMA_SUBBLOCK_RLE_MIN
value|1
define|#
directive|define
name|LZMA_SUBBLOCK_RLE_MAX
value|256
comment|/** 	 * \brief       Subfilter remote control 	 * 	 * When the Subblock filter is initialized, this variable must be 	 * LZMA_SUBFILTER_NONE or LZMA_SUBFILTER_SET. 	 * 	 * When subfilter_mode is LZMA_SUBFILTER_NONE, the application may 	 * put Subfilter options to subfilter_options structure, and then 	 * set subfilter_mode to LZMA_SUBFILTER_SET. No new input data will 	 * be read until the Subfilter has been enabled. Once the Subfilter 	 * has been enabled, liblzma will set subfilter_mode to 	 * LZMA_SUBFILTER_RUN. 	 * 	 * When subfilter_mode is LZMA_SUBFILTER_RUN, the application may 	 * set subfilter_mode to LZMA_SUBFILTER_FINISH. All the input 	 * currently available will be encoded before unsetting the 	 * Subfilter. Application must not change the amount of available 	 * input until the Subfilter has finished. Once the Subfilter has 	 * finished, liblzma will set subfilter_mode to LZMA_SUBFILTER_NONE. 	 * 	 * If the intent is to have Subfilter enabled to the very end of 	 * the data, it is not needed to separately disable Subfilter with 	 * LZMA_SUBFILTER_FINISH. Using LZMA_FINISH as the second argument 	 * of lzma_code() will make the Subblock encoder to disable the 	 * Subfilter once all the data has been ran through the Subfilter. 	 * 	 * After the first call with LZMA_SYNC_FLUSH or LZMA_FINISH, the 	 * application must not change subfilter_mode until LZMA_STREAM_END. 	 * Setting LZMA_SUBFILTER_SET/LZMA_SUBFILTER_FINISH and 	 * LZMA_SYNC_FLUSH/LZMA_FINISH _at the same time_ is fine. 	 * 	 * \note        This variable is ignored if allow_subfilters is false. 	 */
name|lzma_subfilter_mode
name|subfilter_mode
decl_stmt|;
comment|/** 	 * \brief       Subfilter and its options 	 * 	 * When no Subfilter is used, the data is copied as is into Subblocks. 	 * Setting a Subfilter allows encoding some parts of the data with 	 * an additional filter. It is possible to many different Subfilters 	 * in the same Block, although only one can be used at once. 	 * 	 * \note        This variable is ignored if allow_subfilters is false. 	 */
name|lzma_filter
name|subfilter_options
decl_stmt|;
block|}
name|lzma_options_subblock
typedef|;
end_typedef

end_unit

