begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Interface to the CN31XX, CN38XX, and CN58XX hardware DFA engine.  *  *<hr>$Revision: 70030 $<hr>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_DFA_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_DFA_H__
end_define

begin_include
include|#
directive|include
file|"cvmx-llm.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-wqe.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-fpa.h"
end_include

begin_include
include|#
directive|include
file|"executive-config.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CVMX_ENABLE_DFA_FUNCTIONS
end_ifdef

begin_include
include|#
directive|include
file|"cvmx-config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ENABLE_DEPRECATED
end_define

begin_comment
comment|/* Set to enable the old 18/36 bit names */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* Maximum nodes available in a small encoding */
define|#
directive|define
name|CVMX_DFA_NODESM_MAX_NODES
value|((OCTEON_IS_MODEL(OCTEON_CN31XX)) ? 0x8000 : 0x20000)
define|#
directive|define
name|CVMX_DFA_NODESM_SIZE
value|512
comment|/* Size of each node for small encoding */
define|#
directive|define
name|CVMX_DFA_NODELG_SIZE
value|1024
comment|/* Size of each node for large encoding */
define|#
directive|define
name|CVMX_DFA_NODESM_LAST_TERMINAL
value|(CVMX_DFA_NODESM_MAX_NODES-1)
ifdef|#
directive|ifdef
name|ENABLE_DEPRECATED
comment|/* These defines are for compatability with old code. They are deprecated */
define|#
directive|define
name|CVMX_DFA_NODE18_SIZE
value|CVMX_DFA_NODESM_SIZE
define|#
directive|define
name|CVMX_DFA_NODE36_SIZE
value|CVMX_DFA_NODELG_SIZE
define|#
directive|define
name|CVMX_DFA_NODE18_MAX_NODES
value|CVMX_DFA_NODESM_MAX_NODES
define|#
directive|define
name|CVMX_DFA_NODE18_LAST_TERMINAL
value|CVMX_DFA_NODESM_LAST_TERMINAL
endif|#
directive|endif
comment|/**  * Which type of memory encoding is this graph using. Make sure you setup  * the LLM to match.  */
typedef|typedef
enum|enum
block|{
name|CVMX_DFA_GRAPH_TYPE_SM
init|=
literal|0
block|,
name|CVMX_DFA_GRAPH_TYPE_LG
init|=
literal|1
block|,
ifdef|#
directive|ifdef
name|ENABLE_DEPRECATED
name|CVMX_DFA_GRAPH_TYPE_18b
init|=
literal|0
block|,
comment|/* Deprecated */
name|CVMX_DFA_GRAPH_TYPE_36b
init|=
literal|1
comment|/* Deprecated */
endif|#
directive|endif
block|}
name|cvmx_dfa_graph_type_t
typedef|;
comment|/**  * The possible node types.  */
typedef|typedef
enum|enum
block|{
name|CVMX_DFA_NODE_TYPE_NORMAL
init|=
literal|0
block|,
comment|/**< Node is a branch */
name|CVMX_DFA_NODE_TYPE_MARKED
init|=
literal|1
block|,
comment|/**< Node is marked special */
name|CVMX_DFA_NODE_TYPE_TERMINAL
init|=
literal|2
comment|/**< Node is a terminal leaf */
block|}
name|cvmx_dfa_node_type_t
typedef|;
comment|/**  * The possible reasons the DFA stopped processing.  */
typedef|typedef
enum|enum
block|{
name|CVMX_DFA_STOP_REASON_DATA_GONE
init|=
literal|0
block|,
comment|/**< DFA ran out of data */
name|CVMX_DFA_STOP_REASON_PARITY_ERROR
init|=
literal|1
block|,
comment|/**< DFA encountered a memory error */
name|CVMX_DFA_STOP_REASON_FULL
init|=
literal|2
block|,
comment|/**< DFA is full */
name|CVMX_DFA_STOP_REASON_TERMINAL
init|=
literal|3
comment|/**< DFA hit a terminal */
block|}
name|cvmx_dfa_stop_reason_t
typedef|;
comment|/**  * This format describes the DFA pointers in small mode  */
typedef|typedef
union|union
block|{
name|uint64_t
name|u64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|mbz
range|:
literal|32
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|p1
range|:
literal|1
decl_stmt|;
comment|/**< Set if next_node1 is odd parity */
name|uint64_t
name|next_node1
range|:
literal|15
decl_stmt|;
comment|/**< Next node if an odd character match */
name|uint64_t
name|p0
range|:
literal|1
decl_stmt|;
comment|/**< Set if next_node0 is odd parity */
name|uint64_t
name|next_node0
range|:
literal|15
decl_stmt|;
comment|/**< Next node if an even character match */
block|}
name|w32
struct|;
struct|struct
block|{
name|uint64_t
name|mbz
range|:
literal|28
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|p1
range|:
literal|1
decl_stmt|;
comment|/**< Set if next_node1 is odd parity */
name|uint64_t
name|next_node1
range|:
literal|17
decl_stmt|;
comment|/**< Next node if an odd character match */
name|uint64_t
name|p0
range|:
literal|1
decl_stmt|;
comment|/**< Set if next_node0 is odd parity */
name|uint64_t
name|next_node0
range|:
literal|17
decl_stmt|;
comment|/**< Next node if an even character match */
block|}
name|w36
struct|;
struct|struct
comment|/**< @ this structure only applies starting in CN58XX and if DFA_CFG[NRPL_ENA] == 1 and IWORD0[NREPLEN] == 1.  */
block|{
name|uint64_t
name|mbz
range|:
literal|28
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|p1
range|:
literal|1
decl_stmt|;
comment|/**< Set if next_node1 is odd parity */
name|uint64_t
name|per_node_repl1
range|:
literal|1
decl_stmt|;
comment|/**< enable for extra replicaiton for next node (CN58XX) */
name|uint64_t
name|next_node_repl1
range|:
literal|2
decl_stmt|;
comment|/**< extra replicaiton for next node (CN58XX) (if per_node_repl1 is set) */
name|uint64_t
name|next_node1
range|:
literal|14
decl_stmt|;
comment|/**< Next node if an odd character match - IWORD3[Msize], if per_node_repl1==1. */
name|uint64_t
name|p0
range|:
literal|1
decl_stmt|;
comment|/**< Set if next_node0 is odd parity */
name|uint64_t
name|per_node_repl0
range|:
literal|1
decl_stmt|;
comment|/**< enable for extra replicaiton for next node (CN58XX) */
name|uint64_t
name|next_node_repl0
range|:
literal|2
decl_stmt|;
comment|/**< extra replicaiton for next node (CN58XX) (if per_node_repl0 is set) */
name|uint64_t
name|next_node0
range|:
literal|14
decl_stmt|;
comment|/**< Next node if an odd character match - IWORD3[Msize], if per_node_repl0==1. */
block|}
name|w36nrepl_en
struct|;
comment|/**< use when next_node_repl[01] is 1. */
struct|struct
comment|/**< this structure only applies starting in CN58XX and if DFA_CFG[NRPL_ENA] == 1 and IWORD0[NREPLEN] == 1.  */
block|{
name|uint64_t
name|mbz
range|:
literal|28
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|p1
range|:
literal|1
decl_stmt|;
comment|/**< Set if next_node1 is odd parity */
name|uint64_t
name|per_node_repl1
range|:
literal|1
decl_stmt|;
comment|/**< enable for extra replicaiton for next node (CN58XX) */
name|uint64_t
name|next_node1
range|:
literal|16
decl_stmt|;
comment|/**< Next node if an odd character match, if per_node_repl1==0. */
name|uint64_t
name|p0
range|:
literal|1
decl_stmt|;
comment|/**< Set if next_node0 is odd parity */
name|uint64_t
name|per_node_repl0
range|:
literal|1
decl_stmt|;
comment|/**< enable for extra replicaiton for next node (CN58XX) */
name|uint64_t
name|next_node0
range|:
literal|16
decl_stmt|;
comment|/**< Next node if an odd character match, if per_node_repl0==0. */
block|}
name|w36nrepl_dis
struct|;
comment|/**< use when next_node_repl[01] is 0. */
if|#
directive|if
name|defined
argument_list|(
name|ENABLE_DEPRECATED
argument_list|)
operator|&&
operator|!
name|OCTEON_IS_COMMON_BINARY
argument_list|()
if|#
directive|if
name|CVMX_COMPILED_FOR
argument_list|(
name|OCTEON_CN31XX
argument_list|)
struct|struct
comment|/**< @deprecated unnamed reference to members */
block|{
name|uint64_t
name|mbz
range|:
literal|32
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|p1
range|:
literal|1
decl_stmt|;
comment|/**< Set if next_node1 is odd parity */
name|uint64_t
name|next_node1
range|:
literal|15
decl_stmt|;
comment|/**< Next node if an odd character match */
name|uint64_t
name|p0
range|:
literal|1
decl_stmt|;
comment|/**< Set if next_node0 is odd parity */
name|uint64_t
name|next_node0
range|:
literal|15
decl_stmt|;
comment|/**< Next node if an even character match */
block|}
struct|;
elif|#
directive|elif
name|CVMX_COMPILED_FOR
argument_list|(
name|OCTEON_CN38XX
argument_list|)
struct|struct
comment|/**< @deprecated unnamed reference to members */
block|{
name|uint64_t
name|mbz
range|:
literal|28
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|p1
range|:
literal|1
decl_stmt|;
comment|/**< Set if next_node1 is odd parity */
name|uint64_t
name|next_node1
range|:
literal|17
decl_stmt|;
comment|/**< Next node if an odd character match */
name|uint64_t
name|p0
range|:
literal|1
decl_stmt|;
comment|/**< Set if next_node0 is odd parity */
name|uint64_t
name|next_node0
range|:
literal|17
decl_stmt|;
comment|/**< Next node if an even character match */
block|}
struct|;
else|#
directive|else
comment|/* Other chips don't support the deprecated unnamed unions */
endif|#
directive|endif
endif|#
directive|endif
block|}
name|cvmx_dfa_node_next_sm_t
typedef|;
comment|/**  * This format describes the DFA pointers in large mode  */
typedef|typedef
union|union
block|{
name|uint64_t
name|u64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|mbz
range|:
literal|32
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|ecc
range|:
literal|7
decl_stmt|;
comment|/**< ECC checksum on the rest of the bits */
name|cvmx_dfa_node_type_t
name|type
range|:
literal|2
decl_stmt|;
comment|/**< Node type */
name|uint64_t
name|mbz2
range|:
literal|3
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|next_node
range|:
literal|20
decl_stmt|;
comment|/**< Next node */
block|}
name|w32
struct|;
struct|struct
block|{
name|uint64_t
name|mbz
range|:
literal|28
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|ecc
range|:
literal|7
decl_stmt|;
comment|/**< ECC checksum on the rest of the bits */
name|cvmx_dfa_node_type_t
name|type
range|:
literal|2
decl_stmt|;
comment|/**< Node type */
name|uint64_t
name|extra_bits
range|:
literal|5
decl_stmt|;
comment|/**< bits copied to report (PASS3/CN58XX), Must be zero previously */
name|uint64_t
name|next_node_repl
range|:
literal|2
decl_stmt|;
comment|/**< extra replicaiton for next node (PASS3/CN58XX), Must be zero previously */
name|uint64_t
name|next_node
range|:
literal|20
decl_stmt|;
comment|/**< Next node ID,  Note, combine with next_node_repl to use as start_node                                                      for continuation, as in cvmx_dfa_node_next_lgb_t. */
block|}
name|w36
struct|;
if|#
directive|if
name|defined
argument_list|(
name|ENABLE_DEPRECATED
argument_list|)
operator|&&
operator|!
name|OCTEON_IS_COMMON_BINARY
argument_list|()
if|#
directive|if
name|CVMX_COMPILED_FOR
argument_list|(
name|OCTEON_CN31XX
argument_list|)
struct|struct
comment|/**< @deprecated unnamed reference to members */
block|{
name|uint64_t
name|mbz
range|:
literal|32
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|ecc
range|:
literal|7
decl_stmt|;
comment|/**< ECC checksum on the rest of the bits */
name|cvmx_dfa_node_type_t
name|type
range|:
literal|2
decl_stmt|;
comment|/**< Node type */
name|uint64_t
name|mbz2
range|:
literal|3
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|next_node
range|:
literal|20
decl_stmt|;
comment|/**< Next node */
block|}
struct|;
elif|#
directive|elif
name|CVMX_COMPILED_FOR
argument_list|(
name|OCTEON_CN38XX
argument_list|)
struct|struct
comment|/**< @deprecated unnamed reference to members */
block|{
name|uint64_t
name|mbz
range|:
literal|28
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|ecc
range|:
literal|7
decl_stmt|;
comment|/**< ECC checksum on the rest of the bits */
name|cvmx_dfa_node_type_t
name|type
range|:
literal|2
decl_stmt|;
comment|/**< Node type */
name|uint64_t
name|extra_bits
range|:
literal|5
decl_stmt|;
comment|/**< bits copied to report (PASS3/CN58XX), Must be zero previously */
name|uint64_t
name|next_node_repl
range|:
literal|2
decl_stmt|;
comment|/**< extra replicaiton for next node (PASS3/CN58XX), Must be zero previously */
name|uint64_t
name|next_node
range|:
literal|20
decl_stmt|;
comment|/**< Next node ID,  Note, combine with next_node_repl to use as start_node                                                      for continuation, as in cvmx_dfa_node_next_lgb_t. */
block|}
struct|;
else|#
directive|else
comment|/* Other chips don't support the deprecated unnamed unions */
endif|#
directive|endif
endif|#
directive|endif
block|}
name|cvmx_dfa_node_next_lg_t
typedef|;
comment|/**  * This format describes the DFA pointers in large mode, another way  */
typedef|typedef
union|union
block|{
name|uint64_t
name|u64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|mbz
range|:
literal|32
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|ecc
range|:
literal|7
decl_stmt|;
comment|/**< ECC checksum on the rest of the bits */
name|uint64_t
name|type_terminal
range|:
literal|1
decl_stmt|;
comment|/**< Node type */
name|uint64_t
name|type_marked
range|:
literal|1
decl_stmt|;
comment|/**< Node type */
name|uint64_t
name|mbz2
range|:
literal|3
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|next_node
range|:
literal|20
decl_stmt|;
comment|/**< Next node */
block|}
name|w32
struct|;
struct|struct
block|{
name|uint64_t
name|mbz
range|:
literal|28
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|ecc
range|:
literal|7
decl_stmt|;
comment|/**< ECC checksum on the rest of the bits */
name|uint64_t
name|type_terminal
range|:
literal|1
decl_stmt|;
comment|/**< Node type */
name|uint64_t
name|type_marked
range|:
literal|1
decl_stmt|;
comment|/**< Node type */
name|uint64_t
name|extra_bits
range|:
literal|5
decl_stmt|;
comment|/**< bits copied to report (PASS3/CN58XX), Must be zero previously */
name|uint64_t
name|next_node_id_and_repl
range|:
literal|22
decl_stmt|;
comment|/**< Next node ID (and repl for PASS3/CN58XX or repl=0 if not),                                                                  use this as start node for continuation. */
block|}
name|w36
struct|;
if|#
directive|if
name|defined
argument_list|(
name|ENABLE_DEPRECATED
argument_list|)
operator|&&
operator|!
name|OCTEON_IS_COMMON_BINARY
argument_list|()
if|#
directive|if
name|CVMX_COMPILED_FOR
argument_list|(
name|OCTEON_CN31XX
argument_list|)
struct|struct
comment|/**< @deprecated unnamed reference to members */
block|{
name|uint64_t
name|mbz
range|:
literal|32
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|ecc
range|:
literal|7
decl_stmt|;
comment|/**< ECC checksum on the rest of the bits */
name|uint64_t
name|type_terminal
range|:
literal|1
decl_stmt|;
comment|/**< Node type */
name|uint64_t
name|type_marked
range|:
literal|1
decl_stmt|;
comment|/**< Node type */
name|uint64_t
name|mbz2
range|:
literal|3
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|next_node
range|:
literal|20
decl_stmt|;
comment|/**< Next node */
block|}
struct|;
elif|#
directive|elif
name|CVMX_COMPILED_FOR
argument_list|(
name|OCTEON_CN38XX
argument_list|)
struct|struct
comment|/**< @deprecated unnamed reference to members */
block|{
name|uint64_t
name|mbz
range|:
literal|28
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|ecc
range|:
literal|7
decl_stmt|;
comment|/**< ECC checksum on the rest of the bits */
name|uint64_t
name|type_terminal
range|:
literal|1
decl_stmt|;
comment|/**< Node type */
name|uint64_t
name|type_marked
range|:
literal|1
decl_stmt|;
comment|/**< Node type */
name|uint64_t
name|extra_bits
range|:
literal|5
decl_stmt|;
comment|/**< bits copied to report (PASS3/CN58XX), Must be zero previously */
name|uint64_t
name|next_node_id_and_repl
range|:
literal|22
decl_stmt|;
comment|/**< Next node ID (and repl for PASS3/CN58XX or repl=0 if not),                                                                  use this as start node for continuation. */
block|}
struct|;
else|#
directive|else
comment|/* Other chips don't support the deprecated unnamed unions */
endif|#
directive|endif
endif|#
directive|endif
block|}
name|cvmx_dfa_node_next_lgb_t
typedef|;
comment|/**  * This format describes the DFA pointers in large mode  */
typedef|typedef
union|union
block|{
name|uint64_t
name|u64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|mbz
range|:
literal|27
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|x0
range|:
literal|1
decl_stmt|;
comment|/**< XOR of the rest of the bits */
name|uint64_t
name|reserved
range|:
literal|4
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|data
range|:
literal|32
decl_stmt|;
comment|/**< LLM Data */
block|}
name|w32
struct|;
struct|struct
block|{
name|uint64_t
name|mbz
range|:
literal|27
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|x0
range|:
literal|1
decl_stmt|;
comment|/**< XOR of the rest of the bits */
name|uint64_t
name|data
range|:
literal|36
decl_stmt|;
comment|/**< LLM Data */
block|}
name|w36
struct|;
if|#
directive|if
name|defined
argument_list|(
name|ENABLE_DEPRECATED
argument_list|)
operator|&&
operator|!
name|OCTEON_IS_COMMON_BINARY
argument_list|()
if|#
directive|if
name|CVMX_COMPILED_FOR
argument_list|(
name|OCTEON_CN31XX
argument_list|)
struct|struct
comment|/**< @deprecated unnamed reference to members */
block|{
name|uint64_t
name|mbz
range|:
literal|27
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|x0
range|:
literal|1
decl_stmt|;
comment|/**< XOR of the rest of the bits */
name|uint64_t
name|reserved
range|:
literal|4
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|data
range|:
literal|32
decl_stmt|;
comment|/**< LLM Data */
block|}
struct|;
elif|#
directive|elif
name|CVMX_COMPILED_FOR
argument_list|(
name|OCTEON_CN38XX
argument_list|)
struct|struct
comment|/**< @deprecated unnamed reference to members */
block|{
name|uint64_t
name|mbz
range|:
literal|27
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|x0
range|:
literal|1
decl_stmt|;
comment|/**< XOR of the rest of the bits */
name|uint64_t
name|data
range|:
literal|36
decl_stmt|;
comment|/**< LLM Data */
block|}
struct|;
else|#
directive|else
comment|/* Other chips don't support the deprecated unnamed unions */
endif|#
directive|endif
endif|#
directive|endif
block|}
name|cvmx_dfa_node_next_read_t
typedef|;
comment|/**  * This structure defines the data format in the low-latency memory  */
typedef|typedef
union|union
block|{
name|uint64_t
name|u64
decl_stmt|;
name|cvmx_dfa_node_next_sm_t
name|sm
decl_stmt|;
comment|/**< This format describes the DFA pointers in small mode */
name|cvmx_dfa_node_next_lg_t
name|lg
decl_stmt|;
comment|/**< This format describes the DFA pointers in large mode */
name|cvmx_dfa_node_next_lgb_t
name|lgb
decl_stmt|;
comment|/**< This format describes the DFA pointers in large mode, another way */
name|cvmx_dfa_node_next_read_t
name|read
decl_stmt|;
comment|/**< This format describes the DFA pointers in large mode */
ifdef|#
directive|ifdef
name|ENABLE_DEPRECATED
name|cvmx_dfa_node_next_sm_t
name|s18
decl_stmt|;
comment|/**< Deprecated */
name|cvmx_dfa_node_next_lg_t
name|s36
decl_stmt|;
comment|/**< Deprecated */
name|cvmx_dfa_node_next_lgb_t
name|s36b
decl_stmt|;
comment|/**< Deprecated */
endif|#
directive|endif
block|}
name|cvmx_dfa_node_next_t
typedef|;
comment|/**  * These structures define a DFA instruction  */
typedef|typedef
union|union
block|{
name|uint64_t
name|u64
index|[
literal|4
index|]
decl_stmt|;
name|uint32_t
name|u32
decl_stmt|;
struct|struct
block|{
comment|// WORD 0
name|uint64_t
name|gxor
range|:
literal|8
decl_stmt|;
comment|/**< Graph XOR value (PASS3/CN58XX), Must be zero for other chips                                                      or if DFA_CFG[GXOR_ENA] == 0.  */
name|uint64_t
name|nxoren
range|:
literal|1
decl_stmt|;
comment|/**< Node XOR enable (PASS3/CN58XX), Must be zero for other chips                                                      or if DFA_CFG[NXOR_ENA] == 0.  */
name|uint64_t
name|nreplen
range|:
literal|1
decl_stmt|;
comment|/**< Node Replication mode enable (PASS3/CN58XX), Must be zero for other chips                                                      or if DFA_CFG[NRPL_ENA] == 0 or IWORD0[Ty] == 0.  */
if|#
directive|if
literal|0
block|uint64_t snrepl                 : 2;
comment|/**< Start_Node Replication (PASS3/CN58XX), Must be zero for other chips                                                      or if DFA_CFG[NRPL_ENA] == 0 or IWORD0[Ty] == 0 or IWORD0[NREPLEN] == 0.  */
block|uint64_t start_node_id          : 20;
comment|/**< Node to start the walk from */
else|#
directive|else
name|uint64_t
name|start_node
range|:
literal|22
decl_stmt|;
comment|/**< Node to start the walk from, includes ID and snrepl, see notes above. */
endif|#
directive|endif
name|uint64_t
name|unused02
range|:
literal|2
decl_stmt|;
comment|/**< Must be zero */
name|cvmx_llm_replication_t
name|replication
range|:
literal|2
decl_stmt|;
comment|/**< Type of memory replication to use */
name|uint64_t
name|unused03
range|:
literal|3
decl_stmt|;
comment|/**< Must be zero */
name|cvmx_dfa_graph_type_t
name|type
range|:
literal|1
decl_stmt|;
comment|/**< Type of graph */
name|uint64_t
name|unused04
range|:
literal|4
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|base
range|:
literal|20
decl_stmt|;
comment|/**< All tables start on 1KB boundary */
comment|// WORD 1
name|uint64_t
name|input_length
range|:
literal|16
decl_stmt|;
comment|/**< In bytes, # pointers in gather case */
name|uint64_t
name|use_gather
range|:
literal|1
decl_stmt|;
comment|/**< Set to use gather */
name|uint64_t
name|no_L2_alloc
range|:
literal|1
decl_stmt|;
comment|/**< Set to disable loading of the L2 cache by the DFA */
name|uint64_t
name|full_block_write
range|:
literal|1
decl_stmt|;
comment|/**< If set, HW can write entire cache blocks @ result_ptr */
name|uint64_t
name|little_endian
range|:
literal|1
decl_stmt|;
comment|/**< Affects only packet data, not instruction, gather list, or result */
name|uint64_t
name|unused1
range|:
literal|8
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|data_ptr
range|:
literal|36
decl_stmt|;
comment|/**< Either directly points to data or the gather list. If gather list,                                                     data_ptr<2:0> must be zero (i.e. 8B aligned) */
comment|// WORD 2
name|uint64_t
name|max_results
range|:
literal|16
decl_stmt|;
comment|/**< in 64-bit quantities, mbz for store */
name|uint64_t
name|unused2
range|:
literal|12
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|result_ptr
range|:
literal|36
decl_stmt|;
comment|/**< must be 128 byte aligned */
comment|// WORD 3
name|uint64_t
name|tsize
range|:
literal|8
decl_stmt|;
comment|/**< tsize*256 is the number of terminal nodes for GRAPH_TYPE_SM */
name|uint64_t
name|msize
range|:
literal|16
decl_stmt|;
comment|/**< msize is the number of marked nodes for GRAPH_TYPE_SM */
name|uint64_t
name|unused3
range|:
literal|4
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|wq_ptr
range|:
literal|36
decl_stmt|;
comment|/**< 0 for no work queue entry creation */
block|}
name|s
struct|;
block|}
name|cvmx_dfa_command_t
typedef|;
comment|/**  * Format of the first result word written by the hardware.  */
typedef|typedef
union|union
block|{
name|uint64_t
name|u64
decl_stmt|;
struct|struct
block|{
name|cvmx_dfa_stop_reason_t
name|reas
range|:
literal|2
decl_stmt|;
comment|/**< Reason the DFA stopped */
name|uint64_t
name|mbz
range|:
literal|44
decl_stmt|;
comment|/**< Zero */
name|uint64_t
name|last_marked
range|:
literal|1
decl_stmt|;
comment|/**< Set if the last entry written is marked */
name|uint64_t
name|done
range|:
literal|1
decl_stmt|;
comment|/**< Set to 1 when the DFA completes */
name|uint64_t
name|num_entries
range|:
literal|16
decl_stmt|;
comment|/**< Number of result words written */
block|}
name|s
struct|;
block|}
name|cvmx_dfa_result0_t
typedef|;
comment|/**  * Format of the second result word and subsequent result words written by the hardware.  */
typedef|typedef
union|union
block|{
name|uint64_t
name|u64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|byte_offset
range|:
literal|16
decl_stmt|;
comment|/**< Number of bytes consumed */
name|uint64_t
name|extra_bits_high
range|:
literal|4
decl_stmt|;
comment|/**< If PASS3 or CN58XX and DFA_CFG[NRPL_ENA] == 1 and IWORD0[Ty] == 1,                                              then set to<27:24> of the last next-node pointer. Else set to 0x0.  */
name|uint64_t
name|prev_node
range|:
literal|20
decl_stmt|;
comment|/**< Index of the previous node */
name|uint64_t
name|extra_bits_low
range|:
literal|2
decl_stmt|;
comment|/**< If PASS3 or CN58XX and DFA_CFG[NRPL_ENA] == 1 and IWORD0[Ty] == 1,                                              then set to<23:22> of the last next-node pointer. Else set to 0x0.  */
name|uint64_t
name|next_node_repl
range|:
literal|2
decl_stmt|;
comment|/**< If PASS3 or CN58XX and DFA_CFG[NRPL_ENA] == 1 and IWORD0[Ty] == 1, then set                                              to next_node_repl (<21:20>) of the last next-node pointer. Else set to 0x0.  */
name|uint64_t
name|current_node
range|:
literal|20
decl_stmt|;
comment|/**< Index of the current node */
block|}
name|s
struct|;
struct|struct
block|{
name|uint64_t
name|byte_offset
range|:
literal|16
decl_stmt|;
comment|/**< Number of bytes consumed */
name|uint64_t
name|extra_bits_high
range|:
literal|4
decl_stmt|;
comment|/**< If PASS3 or CN58XX and DFA_CFG[NRPL_ENA] == 1 and IWORD0[Ty] == 1,                                              then set to<27:24> of the last next-node pointer. Else set to 0x0.  */
name|uint64_t
name|prev_node
range|:
literal|20
decl_stmt|;
comment|/**< Index of the previous node */
name|uint64_t
name|extra_bits_low
range|:
literal|2
decl_stmt|;
comment|/**< If PASS3 or CN58XX and DFA_CFG[NRPL_ENA] == 1 and IWORD0[Ty] == 1,                                              then set to<23:22> of the last next-node pointer. Else set to 0x0.  */
name|uint64_t
name|curr_id_and_repl
range|:
literal|22
decl_stmt|;
comment|/**< Use ths as start_node for continuation. */
block|}
name|s2
struct|;
block|}
name|cvmx_dfa_result1_t
typedef|;
comment|/**  * Abstract DFA graph  */
typedef|typedef
struct|struct
block|{
name|cvmx_llm_replication_t
name|replication
decl_stmt|;
comment|/**< Level of memory replication to use. Must match the LLM setup */
name|cvmx_dfa_graph_type_t
name|type
decl_stmt|;
comment|/**< Type of graph */
name|uint64_t
name|base_address
decl_stmt|;
comment|/**< LLM start address of the graph */
union|union
block|{
struct|struct
block|{
name|uint64_t
name|gxor
range|:
literal|8
decl_stmt|;
comment|/**< Graph XOR value (PASS3/CN58XX), Must be zero for other chips                                                           or if DFA_CFG[GXOR_ENA] == 0.  */
name|uint64_t
name|nxoren
range|:
literal|1
decl_stmt|;
comment|/**< Node XOR enable (PASS3/CN58XX), Must be zero for other chips                                                           or if DFA_CFG[NXOR_ENA] == 0.  */
name|uint64_t
name|nreplen
range|:
literal|1
decl_stmt|;
comment|/**< Node Replication mode enable (PASS3/CN58XX), Must be zero for other chips                                                           or if DFA_CFG[NRPL_ENA] == 0 or IWORD0[Ty] == 0.  */
name|uint64_t
name|snrepl
range|:
literal|2
decl_stmt|;
comment|/**< Start_Node Replication (PASS3/CN58XX), Must be zero for other chips                                                           or if DFA_CFG[NRPL_ENA] == 0 or IWORD0[Ty] == 0 or IWORD0[NREPLEN] == 0.*/
name|uint64_t
name|start_node_id
range|:
literal|20
decl_stmt|;
comment|/**< Start node index for the root of the graph */
block|}
struct|;
name|uint32_t
name|start_node
decl_stmt|;
comment|/**< Start node index for the root of the graph, incl. snrepl (PASS3/CN58XX)                                                            NOTE: for backwards compatibility this name includes the the                                                                  gxor, nxoren, nreplen, and snrepl fields which will all be                                                                  zero in applicaitons existing before the introduction of these                                                                  fields, so that existing applicaiton do not need to change. */
block|}
union|;
name|int
name|num_terminal_nodes
decl_stmt|;
comment|/**< Number of terminal nodes in the graph. Only needed for small graphs. */
name|int
name|num_marked_nodes
decl_stmt|;
comment|/**< Number of marked nodes in the graph. Only needed for small graphs. */
block|}
name|cvmx_dfa_graph_t
typedef|;
comment|/**  * DFA internal global state -- stored in 8 bytes of FAU  */
typedef|typedef
union|union
block|{
name|uint64_t
name|u64
decl_stmt|;
struct|struct
block|{
define|#
directive|define
name|CVMX_DFA_STATE_TICKET_BIT_POS
value|16
ifdef|#
directive|ifdef
name|__BIG_ENDIAN_BITFIELD
comment|// NOTE:  must clear LSB of base_address_div16 due to ticket overflow
name|uint32_t
name|base_address_div16
decl_stmt|;
comment|/**< Current DFA instruction queue chunck base address/16 (clear LSB). */
name|uint8_t
name|ticket_loops
decl_stmt|;
comment|/**< bits [15:8] of total number of tickets requested. */
name|uint8_t
name|ticket
decl_stmt|;
comment|/**< bits [7:0] of total number of tickets requested (current ticket held). */
comment|// NOTE: index and now_serving are written together
name|uint8_t
name|now_serving
decl_stmt|;
comment|/**< current ticket being served (or ready to be served). */
name|uint8_t
name|index
decl_stmt|;
comment|/**< index into current chunk: (base_address_div16*16)[index] = next entry. */
else|#
directive|else
comment|// NOTE: little endian mode probably won't work
name|uint8_t
name|index
decl_stmt|;
name|uint8_t
name|now_serving
decl_stmt|;
name|uint8_t
name|ticket
decl_stmt|;
name|uint8_t
name|ticket_loops
decl_stmt|;
name|uint32_t
name|base_address_div16
decl_stmt|;
endif|#
directive|endif
block|}
name|s
struct|;
struct|struct
block|{
comment|// a bitfield version of the same thing to extract base address while clearing carry.
ifdef|#
directive|ifdef
name|__BIG_ENDIAN_BITFIELD
name|uint64_t
name|base_address_div32
range|:
literal|31
decl_stmt|;
comment|/**< Current DFA instruction queue chunck base address/32. */
name|uint64_t
name|carry
range|:
literal|1
decl_stmt|;
comment|/**< Carry out from total_tickets. */
name|uint64_t
name|total_tickets
range|:
literal|16
decl_stmt|;
comment|/**< Total tickets. */
name|uint64_t
name|now_serving
range|:
literal|8
decl_stmt|;
comment|/**< current ticket being served (or ready to be served). */
name|uint64_t
name|index
range|:
literal|8
decl_stmt|;
comment|/**< index into current chunk. */
else|#
directive|else
comment|// NOTE: little endian mode probably won't work
name|uint64_t
name|index
range|:
literal|8
decl_stmt|;
name|uint64_t
name|now_serving
range|:
literal|8
decl_stmt|;
name|uint64_t
name|total_tickets
range|:
literal|16
decl_stmt|;
name|uint64_t
name|carry
range|:
literal|1
decl_stmt|;
name|uint64_t
name|base_address_div32
range|:
literal|31
decl_stmt|;
endif|#
directive|endif
block|}
name|s2
struct|;
block|}
name|cvmx_dfa_state_t
typedef|;
comment|/* CSR typedefs have been moved to cvmx-dfa-defs.h */
comment|/**  * Write a small node edge to LLM.  *  * @param graph  Graph to modify  * @param source_node  *               Source node for this edge  * @param match_index  *               Index into the node edge table. This is the match character/2.  * @param destination_node0  *               Destination if the character matches (match_index*2).  * @param destination_node1  *               Destination if the character matches (match_index*2+1).  */
specifier|static
specifier|inline
name|void
name|cvmx_dfa_write_edge_sm
parameter_list|(
specifier|const
name|cvmx_dfa_graph_t
modifier|*
name|graph
parameter_list|,
name|uint64_t
name|source_node
parameter_list|,
name|uint64_t
name|match_index
parameter_list|,
name|uint64_t
name|destination_node0
parameter_list|,
name|uint64_t
name|destination_node1
parameter_list|)
block|{
name|cvmx_llm_address_t
name|address
decl_stmt|;
name|cvmx_dfa_node_next_t
name|next_ptr
decl_stmt|;
name|address
operator|.
name|u64
operator|=
name|graph
operator|->
name|base_address
operator|+
name|source_node
operator|*
name|CVMX_DFA_NODESM_SIZE
operator|+
name|match_index
operator|*
literal|4
expr_stmt|;
name|next_ptr
operator|.
name|u64
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|OCTEON_IS_MODEL
argument_list|(
name|OCTEON_CN31XX
argument_list|)
condition|)
block|{
name|next_ptr
operator|.
name|sm
operator|.
name|w32
operator|.
name|next_node0
operator|=
name|destination_node0
expr_stmt|;
name|next_ptr
operator|.
name|sm
operator|.
name|w32
operator|.
name|p0
operator|=
name|cvmx_llm_parity
argument_list|(
name|destination_node0
argument_list|)
expr_stmt|;
name|next_ptr
operator|.
name|sm
operator|.
name|w32
operator|.
name|next_node1
operator|=
name|destination_node1
expr_stmt|;
name|next_ptr
operator|.
name|sm
operator|.
name|w32
operator|.
name|p1
operator|=
name|cvmx_llm_parity
argument_list|(
name|destination_node1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|next_ptr
operator|.
name|sm
operator|.
name|w36
operator|.
name|next_node0
operator|=
name|destination_node0
expr_stmt|;
name|next_ptr
operator|.
name|sm
operator|.
name|w36
operator|.
name|p0
operator|=
name|cvmx_llm_parity
argument_list|(
name|destination_node0
argument_list|)
expr_stmt|;
name|next_ptr
operator|.
name|sm
operator|.
name|w36
operator|.
name|next_node1
operator|=
name|destination_node1
expr_stmt|;
name|next_ptr
operator|.
name|sm
operator|.
name|w36
operator|.
name|p1
operator|=
name|cvmx_llm_parity
argument_list|(
name|destination_node1
argument_list|)
expr_stmt|;
block|}
name|cvmx_llm_write36
argument_list|(
name|address
argument_list|,
name|next_ptr
operator|.
name|u64
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|ENABLE_DEPRECATED
define|#
directive|define
name|cvmx_dfa_write_edge18
value|cvmx_dfa_write_edge_sm
endif|#
directive|endif
comment|/**  * Write a large node edge to LLM.  *  * @param graph  Graph to modify  * @param source_node  *               Source node for this edge  * @param match  Character to match before taking this edge.  * @param destination_node  *               Destination node of the edge.  * @param destination_type  *               Node type at the end of this edge.  */
specifier|static
specifier|inline
name|void
name|cvmx_dfa_write_node_lg
parameter_list|(
specifier|const
name|cvmx_dfa_graph_t
modifier|*
name|graph
parameter_list|,
name|uint64_t
name|source_node
parameter_list|,
name|unsigned
name|char
name|match
parameter_list|,
name|uint64_t
name|destination_node
parameter_list|,
name|cvmx_dfa_node_type_t
name|destination_type
parameter_list|)
block|{
name|cvmx_llm_address_t
name|address
decl_stmt|;
name|cvmx_dfa_node_next_t
name|next_ptr
decl_stmt|;
name|address
operator|.
name|u64
operator|=
name|graph
operator|->
name|base_address
operator|+
name|source_node
operator|*
name|CVMX_DFA_NODELG_SIZE
operator|+
operator|(
name|uint64_t
operator|)
name|match
operator|*
literal|4
expr_stmt|;
name|next_ptr
operator|.
name|u64
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|OCTEON_IS_MODEL
argument_list|(
name|OCTEON_CN31XX
argument_list|)
condition|)
block|{
name|next_ptr
operator|.
name|lg
operator|.
name|w32
operator|.
name|type
operator|=
name|destination_type
expr_stmt|;
name|next_ptr
operator|.
name|lg
operator|.
name|w32
operator|.
name|next_node
operator|=
name|destination_node
expr_stmt|;
name|next_ptr
operator|.
name|lg
operator|.
name|w32
operator|.
name|ecc
operator|=
name|cvmx_llm_ecc
argument_list|(
name|next_ptr
operator|.
name|u64
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|next_ptr
operator|.
name|lg
operator|.
name|w36
operator|.
name|type
operator|=
name|destination_type
expr_stmt|;
name|next_ptr
operator|.
name|lg
operator|.
name|w36
operator|.
name|next_node
operator|=
name|destination_node
expr_stmt|;
name|next_ptr
operator|.
name|lg
operator|.
name|w36
operator|.
name|ecc
operator|=
name|cvmx_llm_ecc
argument_list|(
name|next_ptr
operator|.
name|u64
argument_list|)
expr_stmt|;
block|}
name|cvmx_llm_write36
argument_list|(
name|address
argument_list|,
name|next_ptr
operator|.
name|u64
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|ENABLE_DEPRECATED
define|#
directive|define
name|cvmx_dfa_write_node36
value|cvmx_dfa_write_node_lg
endif|#
directive|endif
comment|/**  * Ring the DFA doorbell telling it that new commands are  * available.  *  * @param num_commands  *               Number of new commands  */
specifier|static
specifier|inline
name|void
name|cvmx_dfa_write_doorbell
parameter_list|(
name|uint64_t
name|num_commands
parameter_list|)
block|{
name|CVMX_SYNCWS
expr_stmt|;
name|cvmx_write_csr
argument_list|(
name|CVMX_DFA_DBELL
argument_list|,
name|num_commands
argument_list|)
expr_stmt|;
block|}
comment|/**  * @INTERNAL  * Write a new command to the DFA. Calls to this function  * are internally synchronized across all processors, and  * the doorbell is rung during this function.  *  * @param command Command to write  */
ifdef|#
directive|ifdef
name|CVMX_ENABLE_DFA_FUNCTIONS
specifier|static
specifier|inline
name|void
name|__cvmx_dfa_write_command
parameter_list|(
name|cvmx_dfa_command_t
modifier|*
name|command
parameter_list|)
block|{
name|cvmx_dfa_state_t
name|cvmx_dfa_state
decl_stmt|;
name|uint64_t
name|my_ticket
decl_stmt|;
comment|// needs to wrap to 8 bits
name|uint64_t
name|index
decl_stmt|;
name|cvmx_dfa_command_t
modifier|*
name|head
decl_stmt|;
name|CVMX_PREFETCH0
argument_list|(
name|command
argument_list|)
expr_stmt|;
comment|// take a ticket.
name|cvmx_dfa_state
operator|.
name|u64
operator|=
name|cvmx_fau_fetch_and_add64
argument_list|(
name|CVMX_FAU_DFA_STATE
argument_list|,
literal|1ull
operator|<<
name|CVMX_DFA_STATE_TICKET_BIT_POS
argument_list|)
expr_stmt|;
name|my_ticket
operator|=
name|cvmx_dfa_state
operator|.
name|s
operator|.
name|ticket
expr_stmt|;
comment|// see if it is our turn
while|while
condition|(
name|my_ticket
operator|!=
name|cvmx_dfa_state
operator|.
name|s
operator|.
name|now_serving
condition|)
block|{
name|int
name|delta
init|=
name|my_ticket
operator|-
name|cvmx_dfa_state
operator|.
name|s
operator|.
name|now_serving
decl_stmt|;
if|if
condition|(
name|delta
operator|<
literal|0
condition|)
name|delta
operator|+=
literal|256
expr_stmt|;
name|cvmx_wait
argument_list|(
literal|10
operator|*
name|delta
argument_list|)
expr_stmt|;
comment|// reduce polling load on system
name|cvmx_dfa_state
operator|.
name|u64
operator|=
name|cvmx_fau_fetch_and_add64
argument_list|(
name|CVMX_FAU_DFA_STATE
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// poll for my_ticket==now_serving
block|}
comment|// compute index and instruction queue head pointer
name|index
operator|=
name|cvmx_dfa_state
operator|.
name|s
operator|.
name|index
expr_stmt|;
comment|// NOTE: the DFA only supports 36-bit addressing
name|head
operator|=
operator|&
operator|(
operator|(
name|CASTPTR
argument_list|(
name|cvmx_dfa_command_t
argument_list|,
operator|(
name|cvmx_dfa_state
operator|.
name|s2
operator|.
name|base_address_div32
operator|*
literal|32ull
operator|)
argument_list|)
index|[
name|index
index|]
operator|)
operator|)
expr_stmt|;
name|head
operator|=
operator|(
name|cvmx_dfa_command_t
operator|*
operator|)
name|cvmx_phys_to_ptr
argument_list|(
name|CAST64
argument_list|(
name|head
argument_list|)
argument_list|)
expr_stmt|;
comment|// NOTE: since we are not storing bit 63 of address, we must set it now
comment|// copy the command to the instruction queue
operator|*
name|head
operator|++
operator|=
operator|*
name|command
expr_stmt|;
comment|// check if a new chunk is needed
if|if
condition|(
name|cvmx_unlikely
argument_list|(
operator|(
operator|++
name|index
operator|>=
operator|(
operator|(
name|CVMX_FPA_DFA_POOL_SIZE
operator|-
literal|8
operator|)
operator|/
sizeof|sizeof
argument_list|(
name|cvmx_dfa_command_t
argument_list|)
operator|)
operator|)
argument_list|)
condition|)
block|{
name|uint64_t
modifier|*
name|new_base
init|=
operator|(
name|uint64_t
operator|*
operator|)
name|cvmx_fpa_alloc
argument_list|(
name|CVMX_FPA_DFA_POOL
argument_list|)
decl_stmt|;
comment|// could make this async
if|if
condition|(
name|new_base
condition|)
block|{
comment|// put the link into the instruction queue's "Next Chunk Buffer Ptr"
operator|*
operator|(
name|uint64_t
operator|*
operator|)
name|head
operator|=
name|cvmx_ptr_to_phys
argument_list|(
name|new_base
argument_list|)
expr_stmt|;
comment|// update our state (note 32-bit write to not disturb other fields)
name|cvmx_fau_atomic_write32
argument_list|(
call|(
name|cvmx_fau_reg_32_t
call|)
argument_list|(
name|CVMX_FAU_DFA_STATE
operator|+
operator|(
name|CAST64
argument_list|(
operator|&
name|cvmx_dfa_state
operator|.
name|s
operator|.
name|base_address_div16
argument_list|)
operator|-
name|CAST64
argument_list|(
operator|&
name|cvmx_dfa_state
argument_list|)
operator|)
argument_list|)
argument_list|,
operator|(
name|CAST64
argument_list|(
name|new_base
argument_list|)
operator|)
operator|/
literal|16
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|cvmx_dprintf
argument_list|(
literal|"__cvmx_dfa_write_command: Out of memory. Expect crashes.\n"
argument_list|)
expr_stmt|;
block|}
name|index
operator|=
literal|0
expr_stmt|;
block|}
name|cvmx_dfa_write_doorbell
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// update index and now_serving in the DFA state FAU location (NOTE: this write16 updates to 8-bit values.)
comment|// NOTE: my_ticket+1 carry out is lost due to write16 and index has already been wrapped to fit in uint8.
name|cvmx_fau_atomic_write16
argument_list|(
call|(
name|cvmx_fau_reg_16_t
call|)
argument_list|(
name|CVMX_FAU_DFA_STATE
operator|+
operator|(
name|CAST64
argument_list|(
operator|&
name|cvmx_dfa_state
operator|.
name|s
operator|.
name|now_serving
argument_list|)
operator|-
name|CAST64
argument_list|(
operator|&
name|cvmx_dfa_state
argument_list|)
operator|)
argument_list|)
argument_list|,
operator|(
operator|(
name|my_ticket
operator|+
literal|1
operator|)
operator|<<
literal|8
operator|)
operator||
name|index
argument_list|)
expr_stmt|;
block|}
comment|/**  * Submit work to the DFA units for processing  *  * @param graph   Graph to process  * @param start_node  *                The node to start (or continue) walking from  *                includes. start_node_id and snrepl (PASS3/CN58XX), but gxor,  *                nxoren, and nreplen are taken from the graph structure  * @param input   The input to match against  * @param input_length  *                The length of the input in bytes  * @param use_gather  *		  The input and input_length are of a gather list  * @param is_little_endian  *                Set to 1 if the input is in little endian format and must  *                be swapped before compare.  * @param result  Location the DFA should put the results in. This must be  *                an area sized in multiples of a cache line.  * @param max_results  *                The maximum number of 64-bit result1 words after result0.  *                That is, "size of the result area in 64-bit words" - 1.  *                max_results must be at least 1.  * @param work    Work queue entry to submit when DFA completes. Can be NULL.  */
specifier|static
specifier|inline
name|void
name|cvmx_dfa_submit
parameter_list|(
specifier|const
name|cvmx_dfa_graph_t
modifier|*
name|graph
parameter_list|,
name|int
name|start_node
parameter_list|,
name|void
modifier|*
name|input
parameter_list|,
name|int
name|input_length
parameter_list|,
name|int
name|use_gather
parameter_list|,
name|int
name|is_little_endian
parameter_list|,
name|cvmx_dfa_result0_t
modifier|*
name|result
parameter_list|,
name|int
name|max_results
parameter_list|,
name|cvmx_wqe_t
modifier|*
name|work
parameter_list|)
block|{
name|cvmx_dfa_command_t
name|command
decl_stmt|;
comment|/* Make sure the result's first 64bit word is zero so we can tell when the         DFA is done. */
name|result
operator|->
name|u64
operator|=
literal|0
expr_stmt|;
comment|// WORD 0
name|command
operator|.
name|u64
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
name|command
operator|.
name|s
operator|.
name|gxor
operator|=
name|graph
operator|->
name|gxor
expr_stmt|;
comment|// (PASS3/CN58XX)
name|command
operator|.
name|s
operator|.
name|nxoren
operator|=
name|graph
operator|->
name|nxoren
expr_stmt|;
comment|// (PASS3/CN58XX)
name|command
operator|.
name|s
operator|.
name|nreplen
operator|=
name|graph
operator|->
name|nreplen
expr_stmt|;
comment|// (PASS3/CN58XX)
name|command
operator|.
name|s
operator|.
name|start_node
operator|=
name|start_node
expr_stmt|;
comment|// includes snrepl (PASS3/CN58XX)
name|command
operator|.
name|s
operator|.
name|replication
operator|=
name|graph
operator|->
name|replication
expr_stmt|;
name|command
operator|.
name|s
operator|.
name|type
operator|=
name|graph
operator|->
name|type
expr_stmt|;
name|command
operator|.
name|s
operator|.
name|base
operator|=
name|graph
operator|->
name|base_address
operator|>>
literal|10
expr_stmt|;
comment|// WORD 1
name|command
operator|.
name|u64
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
name|command
operator|.
name|s
operator|.
name|input_length
operator|=
name|input_length
expr_stmt|;
name|command
operator|.
name|s
operator|.
name|use_gather
operator|=
name|use_gather
expr_stmt|;
name|command
operator|.
name|s
operator|.
name|no_L2_alloc
operator|=
literal|0
expr_stmt|;
name|command
operator|.
name|s
operator|.
name|full_block_write
operator|=
literal|1
expr_stmt|;
name|command
operator|.
name|s
operator|.
name|little_endian
operator|=
name|is_little_endian
expr_stmt|;
name|command
operator|.
name|s
operator|.
name|data_ptr
operator|=
name|cvmx_ptr_to_phys
argument_list|(
name|input
argument_list|)
expr_stmt|;
comment|// WORD 2
name|command
operator|.
name|u64
index|[
literal|2
index|]
operator|=
literal|0
expr_stmt|;
name|command
operator|.
name|s
operator|.
name|max_results
operator|=
name|max_results
expr_stmt|;
name|command
operator|.
name|s
operator|.
name|result_ptr
operator|=
name|cvmx_ptr_to_phys
argument_list|(
name|result
argument_list|)
expr_stmt|;
comment|// WORD 3
name|command
operator|.
name|u64
index|[
literal|3
index|]
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|graph
operator|->
name|type
operator|==
name|CVMX_DFA_GRAPH_TYPE_SM
condition|)
block|{
name|command
operator|.
name|s
operator|.
name|tsize
operator|=
operator|(
name|graph
operator|->
name|num_terminal_nodes
operator|+
literal|255
operator|)
operator|/
literal|256
expr_stmt|;
name|command
operator|.
name|s
operator|.
name|msize
operator|=
name|graph
operator|->
name|num_marked_nodes
expr_stmt|;
block|}
name|command
operator|.
name|s
operator|.
name|wq_ptr
operator|=
name|cvmx_ptr_to_phys
argument_list|(
name|work
argument_list|)
expr_stmt|;
name|__cvmx_dfa_write_command
argument_list|(
operator|&
name|command
argument_list|)
expr_stmt|;
comment|// NOTE: this does synchronization and rings doorbell
block|}
endif|#
directive|endif
comment|/**  * DFA gather list element  */
typedef|typedef
struct|struct
block|{
name|uint64_t
name|length
range|:
literal|16
decl_stmt|;
comment|/**< length of piece of data at addr */
name|uint64_t
name|reserved
range|:
literal|12
decl_stmt|;
comment|/**< reserved, set to 0 */
name|uint64_t
name|addr
range|:
literal|36
decl_stmt|;
comment|/**< pointer to piece of data */
block|}
name|cvmx_dfa_gather_entry_t
typedef|;
comment|/**  * Check if a DFA has completed processing  *  * @param result_ptr Result area the DFA is using  * @return Non zero if the DFA is done  */
specifier|static
specifier|inline
name|uint64_t
name|cvmx_dfa_is_done
parameter_list|(
name|cvmx_dfa_result0_t
modifier|*
name|result_ptr
parameter_list|)
block|{
comment|/* DFA sets the first result 64bit word to non zero when it's done */
return|return
operator|(
operator|(
specifier|volatile
name|cvmx_dfa_result0_t
operator|*
operator|)
name|result_ptr
operator|)
operator|->
name|s
operator|.
name|done
return|;
block|}
ifdef|#
directive|ifdef
name|CVMX_ENABLE_DFA_FUNCTIONS
comment|/**  * Initialize the DFA hardware before use  * Returns 0 on success, -1 on failure  */
name|int
name|cvmx_dfa_initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * Shutdown and cleanup resources used by the DFA  */
name|void
name|cvmx_dfa_shutdown
parameter_list|(
name|void
parameter_list|)
function_decl|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CVMX_DFA_H__ */
end_comment

end_unit

