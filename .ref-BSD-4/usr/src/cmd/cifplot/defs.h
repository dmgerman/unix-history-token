begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|InBufSize
value|128
end_define

begin_comment
comment|/* Initial allocation for in_buf */
end_comment

begin_define
define|#
directive|define
name|FStackSize
value|6
end_define

begin_comment
comment|/* Maximum size of input file Stack 				 * Used for included files         */
end_comment

begin_define
define|#
directive|define
name|TableSize
value|256
end_define

begin_comment
comment|/* Size of the hash table for 				 * symbol lookup		*/
end_comment

begin_define
define|#
directive|define
name|InstanceTable
value|256
end_define

begin_comment
comment|/* Size of the hash table to store 				 * the inactive items.		*/
end_comment

begin_define
define|#
directive|define
name|UTBLSIZE
value|256
end_define

begin_comment
comment|/* Size of hash table for unactive 				 * elements */
end_comment

begin_define
define|#
directive|define
name|NUM_LAYERS
value|8
end_define

begin_comment
comment|/* Initial size of array holding 				 * the patterns			*/
end_comment

begin_define
define|#
directive|define
name|NO_PAT_LINE
value|8
end_define

begin_comment
comment|/* Number of lines in the stipple 				 * pattern			*/
end_comment

begin_define
define|#
directive|define
name|OUT_BUF_SIZE
value|32
end_define

begin_comment
comment|/* Number of scan lines sent to plotter  				 * at a time			*/
end_comment

begin_comment
comment|/****************************************************************/
end_comment

begin_define
define|#
directive|define
name|NOPLOT
value|0
end_define

begin_define
define|#
directive|define
name|VARIAN
value|1
end_define

begin_define
define|#
directive|define
name|VERSATEC
value|2
end_define

begin_define
define|#
directive|define
name|LINEPRINTER
value|3
end_define

begin_define
define|#
directive|define
name|VSPOOL
value|4
end_define

begin_define
define|#
directive|define
name|HP2648A
value|5
end_define

begin_define
define|#
directive|define
name|INTERNAL
value|1
end_define

begin_comment
comment|/* Internal Error		*/
end_comment

begin_define
define|#
directive|define
name|RUNTIME
value|2
end_define

begin_comment
comment|/* Run Time Error		*/
end_comment

begin_define
define|#
directive|define
name|FATAL
value|3
end_define

begin_comment
comment|/* Fatal Error(abortion delayed)*/
end_comment

begin_define
define|#
directive|define
name|RECOVERABLE
value|4
end_define

begin_comment
comment|/* Recoverable Error		*/
end_comment

begin_define
define|#
directive|define
name|WARNING
value|5
end_define

begin_comment
comment|/* Warning Only			*/
end_comment

begin_define
define|#
directive|define
name|NIL
value|0
end_define

begin_comment
comment|/* NIL pointer 			*/
end_comment

begin_define
define|#
directive|define
name|DEBUG
value|if(debug) printf
end_define

begin_define
define|#
directive|define
name|ADEBUG
value|1
end_define

begin_comment
comment|/* Debugging flag		*/
end_comment

begin_define
define|#
directive|define
name|infinity
value|0x7FFFFFFF
end_define

begin_define
define|#
directive|define
name|INFINITY
value|0x7FFFFFFF
end_define

begin_typedef
typedef|typedef
name|float
name|real
typedef|;
end_typedef

begin_define
define|#
directive|define
name|elseif
value|else if
end_define

begin_define
define|#
directive|define
name|ROUND
parameter_list|(
name|x
parameter_list|)
value|((int) (x+0.5))
end_define

begin_define
define|#
directive|define
name|TRUNC
parameter_list|(
name|x
parameter_list|)
value|((int) (x))
end_define

begin_define
define|#
directive|define
name|ABS
parameter_list|(
name|x
parameter_list|)
value|( (x)> 0 ? (x) : -(x))
end_define

begin_define
define|#
directive|define
name|ALLOC
parameter_list|(
name|x
parameter_list|)
value|(x *) alloc(sizeof(x))
end_define

begin_define
define|#
directive|define
name|SWAP
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|t
parameter_list|)
value|t=x; x=y; y=t
end_define

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|( (x)< (y) ? (x) : (y) )
end_define

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|( (x)> (y) ? (x) : (y) )
end_define

begin_define
define|#
directive|define
name|CONVERT
parameter_list|(
name|x
parameter_list|)
value|((int) (((x) - Window.ymin) * ConvertFactor))
end_define

begin_define
define|#
directive|define
name|REVCONVERT
parameter_list|(
name|x
parameter_list|)
value|((real) (((x)/ConvertFactor) + Window.ymin))
end_define

begin_define
define|#
directive|define
name|IMPORT
value|extern
end_define

begin_define
define|#
directive|define
name|FORWARD
value|extern
end_define

end_unit

