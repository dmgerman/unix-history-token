begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * FORE Systems 200-Series Adapter Support  * ---------------------------------------  *  * Virtual Channel Management  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/socketvar.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<netatm/port.h>
end_include

begin_include
include|#
directive|include
file|<netatm/queue.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_sys.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_sap.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_cm.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_if.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_vc.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_stack.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_pcb.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_var.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<dev/hfa/fore.h>
end_include

begin_include
include|#
directive|include
file|<dev/hfa/fore_aali.h>
end_include

begin_include
include|#
directive|include
file|<dev/hfa/fore_slave.h>
end_include

begin_include
include|#
directive|include
file|<dev/hfa/fore_stats.h>
end_include

begin_include
include|#
directive|include
file|<dev/hfa/fore_var.h>
end_include

begin_include
include|#
directive|include
file|<dev/hfa/fore_include.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"@(#) $FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * VCC Stack Instantiation  *   * This function is called via the common driver code during a device VCC  * stack instantiation.  The common code has already validated some of  * the request so we just need to check a few more Fore-specific details.  *  * Called at splnet.  *  * Arguments:  *	cup	pointer to device common unit  *	cvp	pointer to common VCC entry  *  * Returns:  *	0	instantiation successful  *	err 	instantiation failed - reason indicated  *  */
end_comment

begin_function
name|int
name|fore_instvcc
parameter_list|(
name|cup
parameter_list|,
name|cvp
parameter_list|)
name|Cmn_unit
modifier|*
name|cup
decl_stmt|;
name|Cmn_vcc
modifier|*
name|cvp
decl_stmt|;
block|{
name|Fore_vcc
modifier|*
name|fvp
init|=
operator|(
name|Fore_vcc
operator|*
operator|)
name|cvp
decl_stmt|;
name|Atm_attributes
modifier|*
name|ap
init|=
operator|&
name|fvp
operator|->
name|fv_connvc
operator|->
name|cvc_attr
decl_stmt|;
comment|/* 	 * Validate requested AAL 	 */
switch|switch
condition|(
name|ap
operator|->
name|aal
operator|.
name|type
condition|)
block|{
case|case
name|ATM_AAL0
case|:
name|fvp
operator|->
name|fv_aal
operator|=
name|FORE_AAL_0
expr_stmt|;
break|break;
case|case
name|ATM_AAL3_4
case|:
name|fvp
operator|->
name|fv_aal
operator|=
name|FORE_AAL_4
expr_stmt|;
if|if
condition|(
operator|(
name|ap
operator|->
name|aal
operator|.
name|v
operator|.
name|aal4
operator|.
name|forward_max_SDU_size
operator|>
name|FORE_IFF_MTU
operator|)
operator|||
operator|(
name|ap
operator|->
name|aal
operator|.
name|v
operator|.
name|aal4
operator|.
name|backward_max_SDU_size
operator|>
name|FORE_IFF_MTU
operator|)
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
break|break;
case|case
name|ATM_AAL5
case|:
name|fvp
operator|->
name|fv_aal
operator|=
name|FORE_AAL_5
expr_stmt|;
if|if
condition|(
operator|(
name|ap
operator|->
name|aal
operator|.
name|v
operator|.
name|aal5
operator|.
name|forward_max_SDU_size
operator|>
name|FORE_IFF_MTU
operator|)
operator|||
operator|(
name|ap
operator|->
name|aal
operator|.
name|v
operator|.
name|aal5
operator|.
name|backward_max_SDU_size
operator|>
name|FORE_IFF_MTU
operator|)
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
break|break;
default|default:
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|u_int
name|rate_tab
index|[
literal|255
index|]
init|=
block|{
literal|353207
block|,
comment|/*   0 */
literal|312501
block|,
comment|/*   1 */
literal|312501
block|,
comment|/*   2 */
literal|312501
block|,
comment|/*   3 */
literal|312501
block|,
comment|/*   4 */
literal|312501
block|,
comment|/*   5 */
literal|312501
block|,
comment|/*   6 */
literal|312501
block|,
comment|/*   7 */
literal|312501
block|,
comment|/*   8 */
literal|312501
block|,
comment|/*   9 */
literal|312501
block|,
comment|/*  10 */
literal|312501
block|,
comment|/*  11 */
literal|312501
block|,
comment|/*  12 */
literal|312501
block|,
comment|/*  13 */
literal|312501
block|,
comment|/*  14 */
literal|312501
block|,
comment|/*  15 */
literal|312501
block|,
comment|/*  16 */
literal|312501
block|,
comment|/*  17 */
literal|284091
block|,
comment|/*  18 */
literal|284091
block|,
comment|/*  19 */
literal|284091
block|,
comment|/*  20 */
literal|284091
block|,
comment|/*  21 */
literal|284091
block|,
comment|/*  22 */
literal|284091
block|,
comment|/*  23 */
literal|284091
block|,
comment|/*  24 */
literal|284091
block|,
comment|/*  25 */
literal|284091
block|,
comment|/*  26 */
literal|284091
block|,
comment|/*  27 */
literal|284091
block|,
comment|/*  28 */
literal|284091
block|,
comment|/*  29 */
literal|284091
block|,
comment|/*  30 */
literal|284091
block|,
comment|/*  31 */
literal|284091
block|,
comment|/*  32 */
literal|284091
block|,
comment|/*  33 */
literal|284091
block|,
comment|/*  34 */
literal|284091
block|,
comment|/*  35 */
literal|284091
block|,
comment|/*  36 */
literal|284091
block|,
comment|/*  37 */
literal|284091
block|,
comment|/*  38 */
literal|260417
block|,
comment|/*  39 */
literal|260417
block|,
comment|/*  40 */
literal|260417
block|,
comment|/*  41 */
literal|260417
block|,
comment|/*  42 */
literal|260417
block|,
comment|/*  43 */
literal|260417
block|,
comment|/*  44 */
literal|260417
block|,
comment|/*  45 */
literal|260417
block|,
comment|/*  46 */
literal|260417
block|,
comment|/*  47 */
literal|260417
block|,
comment|/*  48 */
literal|260417
block|,
comment|/*  49 */
literal|260417
block|,
comment|/*  50 */
literal|260417
block|,
comment|/*  51 */
literal|260417
block|,
comment|/*  52 */
literal|260417
block|,
comment|/*  53 */
literal|260417
block|,
comment|/*  54 */
literal|260417
block|,
comment|/*  55 */
literal|240385
block|,
comment|/*  56 */
literal|240385
block|,
comment|/*  57 */
literal|240385
block|,
comment|/*  58 */
literal|240385
block|,
comment|/*  59 */
literal|240385
block|,
comment|/*  60 */
literal|240385
block|,
comment|/*  61 */
literal|240385
block|,
comment|/*  62 */
literal|240385
block|,
comment|/*  63 */
literal|240385
block|,
comment|/*  64 */
literal|240385
block|,
comment|/*  65 */
literal|240385
block|,
comment|/*  66 */
literal|240385
block|,
comment|/*  67 */
literal|240385
block|,
comment|/*  68 */
literal|240385
block|,
comment|/*  69 */
literal|240385
block|,
comment|/*  70 */
literal|223215
block|,
comment|/*  71 */
literal|223215
block|,
comment|/*  72 */
literal|223215
block|,
comment|/*  73 */
literal|223215
block|,
comment|/*  74 */
literal|223215
block|,
comment|/*  75 */
literal|223215
block|,
comment|/*  76 */
literal|223215
block|,
comment|/*  77 */
literal|223215
block|,
comment|/*  78 */
literal|223215
block|,
comment|/*  79 */
literal|223215
block|,
comment|/*  80 */
literal|223215
block|,
comment|/*  81 */
literal|223215
block|,
comment|/*  82 */
literal|223215
block|,
comment|/*  83 */
literal|208334
block|,
comment|/*  84 */
literal|208334
block|,
comment|/*  85 */
literal|208334
block|,
comment|/*  86 */
literal|208334
block|,
comment|/*  87 */
literal|208334
block|,
comment|/*  88 */
literal|208334
block|,
comment|/*  89 */
literal|208334
block|,
comment|/*  90 */
literal|208334
block|,
comment|/*  91 */
literal|208334
block|,
comment|/*  92 */
literal|208334
block|,
comment|/*  93 */
literal|208334
block|,
comment|/*  94 */
literal|195313
block|,
comment|/*  95 */
literal|195313
block|,
comment|/*  96 */
literal|195313
block|,
comment|/*  97 */
literal|195313
block|,
comment|/*  98 */
literal|195313
block|,
comment|/* 101 */
literal|195313
block|,
comment|/* 102 */
literal|195313
block|,
comment|/* 103 */
literal|183824
block|,
comment|/* 104 */
literal|183824
block|,
comment|/* 105 */
literal|183824
block|,
comment|/* 106 */
literal|183824
block|,
comment|/* 107 */
literal|183824
block|,
comment|/* 108 */
literal|183824
block|,
comment|/* 109 */
literal|183824
block|,
comment|/* 110 */
literal|183824
block|,
comment|/* 111 */
literal|183824
block|,
comment|/* 112 */
literal|173612
block|,
comment|/* 113 */
literal|173612
block|,
comment|/* 114 */
literal|173612
block|,
comment|/* 115 */
literal|173612
block|,
comment|/* 116 */
literal|173612
block|,
comment|/* 117 */
literal|173612
block|,
comment|/* 118 */
literal|173612
block|,
comment|/* 119 */
literal|173612
block|,
comment|/* 120 */
literal|164474
block|,
comment|/* 121 */
literal|164474
block|,
comment|/* 122 */
literal|164474
block|,
comment|/* 123 */
literal|164474
block|,
comment|/* 124 */
literal|164474
block|,
comment|/* 125 */
literal|164474
block|,
comment|/* 126 */
literal|164474
block|,
comment|/* 127 */
literal|156250
block|,
comment|/* 128 */
literal|156250
block|,
comment|/* 129 */
literal|156250
block|,
comment|/* 130 */
literal|156250
block|,
comment|/* 131 */
literal|156250
block|,
comment|/* 132 */
literal|156250
block|,
comment|/* 133 */
literal|148810
block|,
comment|/* 134 */
literal|148810
block|,
comment|/* 135 */
literal|148810
block|,
comment|/* 136 */
literal|148810
block|,
comment|/* 137 */
literal|148810
block|,
comment|/* 138 */
literal|148810
block|,
comment|/* 139 */
literal|142046
block|,
comment|/* 140 */
literal|142046
block|,
comment|/* 141 */
literal|142046
block|,
comment|/* 142 */
literal|142046
block|,
comment|/* 143 */
literal|142046
block|,
comment|/* 144 */
literal|135870
block|,
comment|/* 145 */
literal|135870
block|,
comment|/* 146 */
literal|135870
block|,
comment|/* 147 */
literal|135870
block|,
comment|/* 148 */
literal|130209
block|,
comment|/* 149 */
literal|130209
block|,
comment|/* 150 */
literal|130209
block|,
comment|/* 151 */
literal|130209
block|,
comment|/* 152 */
literal|130209
block|,
comment|/* 153 */
literal|125000
block|,
comment|/* 154 */
literal|125000
block|,
comment|/* 155 */
literal|125000
block|,
comment|/* 156 */
literal|125000
block|,
comment|/* 157 */
literal|120193
block|,
comment|/* 158 */
literal|120193
block|,
comment|/* 159 */
literal|120193
block|,
comment|/* 160 */
literal|115741
block|,
comment|/* 161 */
literal|115741
block|,
comment|/* 162 */
literal|115741
block|,
comment|/* 163 */
literal|115741
block|,
comment|/* 164 */
literal|111608
block|,
comment|/* 165 */
literal|111608
block|,
comment|/* 166 */
literal|111608
block|,
comment|/* 167 */
literal|107759
block|,
comment|/* 168 */
literal|107759
block|,
comment|/* 169 */
literal|107759
block|,
comment|/* 170 */
literal|104167
block|,
comment|/* 171 */
literal|104167
block|,
comment|/* 172 */
literal|104167
block|,
comment|/* 173 */
literal|100807
block|,
comment|/* 174 */
literal|100807
block|,
comment|/* 175 */
literal|97657
block|,
comment|/* 176 */
literal|97657
block|,
comment|/* 177 */
literal|97657
block|,
comment|/* 178 */
literal|94697
block|,
comment|/* 179 */
literal|94697
block|,
comment|/* 180 */
literal|91912
block|,
comment|/* 181 */
literal|91912
block|,
comment|/* 182 */
literal|89286
block|,
comment|/* 183 */
literal|89286
block|,
comment|/* 184 */
literal|86806
block|,
comment|/* 185 */
literal|86806
block|,
comment|/* 186 */
literal|84460
block|,
comment|/* 187 */
literal|84460
block|,
comment|/* 188 */
literal|82237
block|,
comment|/* 189 */
literal|82237
block|,
comment|/* 190 */
literal|80129
block|,
comment|/* 191 */
literal|78125
block|,
comment|/* 192 */
literal|78126
block|,
comment|/* 193 */
literal|76220
block|,
comment|/* 194 */
literal|74405
block|,
comment|/* 195 */
literal|74405
block|,
comment|/* 196 */
literal|72675
block|,
comment|/* 197 */
literal|71023
block|,
comment|/* 198 */
literal|69445
block|,
comment|/* 199 */
literal|69445
block|,
comment|/* 200 */
literal|67935
block|,
comment|/* 201 */
literal|66490
block|,
comment|/* 202 */
literal|65105
block|,
comment|/* 203 */
literal|63776
block|,
comment|/* 204 */
literal|62500
block|,
comment|/* 205 */
literal|61275
block|,
comment|/* 206 */
literal|60097
block|,
comment|/* 207 */
literal|58963
block|,
comment|/* 208 */
literal|57871
block|,
comment|/* 209 */
literal|56819
block|,
comment|/* 210 */
literal|54825
block|,
comment|/* 211 */
literal|53880
block|,
comment|/* 212 */
literal|52967
block|,
comment|/* 213 */
literal|51230
block|,
comment|/* 214 */
literal|50404
block|,
comment|/* 215 */
literal|48829
block|,
comment|/* 216 */
literal|47349
block|,
comment|/* 217 */
literal|46642
block|,
comment|/* 218 */
literal|45290
block|,
comment|/* 219 */
literal|44015
block|,
comment|/* 220 */
literal|42809
block|,
comment|/* 221 */
literal|41119
block|,
comment|/* 222 */
literal|40065
block|,
comment|/* 223 */
literal|39063
block|,
comment|/* 224 */
literal|37651
block|,
comment|/* 225 */
literal|36338
block|,
comment|/* 226 */
literal|35113
block|,
comment|/* 227 */
literal|33968
block|,
comment|/* 228 */
literal|32553
block|,
comment|/* 229 */
literal|31250
block|,
comment|/* 230 */
literal|30049
block|,
comment|/* 231 */
literal|28936
block|,
comment|/* 232 */
literal|27655
block|,
comment|/* 233 */
literal|26261
block|,
comment|/* 234 */
literal|25000
block|,
comment|/* 235 */
literal|23855
block|,
comment|/* 236 */
literal|22645
block|,
comment|/* 237 */
literal|21259
block|,
comment|/* 238 */
literal|20033
block|,
comment|/* 239 */
literal|18826
block|,
comment|/* 240 */
literal|17557
block|,
comment|/* 241 */
literal|16277
block|,
comment|/* 242 */
literal|15025
block|,
comment|/* 243 */
literal|13767
block|,
comment|/* 244 */
literal|12551
block|,
comment|/* 245 */
literal|11282
block|,
comment|/* 246 */
literal|10017
block|,
comment|/* 247 */
literal|8779
block|,
comment|/* 248 */
literal|7531
block|,
comment|/* 249 */
literal|6263
block|,
comment|/* 250 */
literal|5017
block|,
comment|/* 251 */
literal|3761
block|,
comment|/* 252 */
literal|2509
block|,
comment|/* 253 */
literal|1254
block|,
comment|/* 254 */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Find the best match of the high part of the Rate Control Information  *   * This function is called when a VC is opened in order to help  * in converting Fore's rate to PCR.  * The Fore's Rate Control Information is encoded as 32-bit field  * comprised of two 16-bit subfields.  *  * Arguments:  *	*pcr		Peak Cell Rate, will be updated with actual value  *  * Returns:  *	descr		the rate descriptor  *  */
end_comment

begin_function
specifier|static
name|uint32_t
name|pcr2rate
parameter_list|(
name|int32_t
modifier|*
name|pcr
parameter_list|)
block|{
name|u_int
name|i
decl_stmt|;
if|if
condition|(
operator|*
name|pcr
operator|>=
name|rate_tab
index|[
literal|0
index|]
condition|)
block|{
comment|/* special case link rate */
operator|*
name|pcr
operator|=
name|rate_tab
index|[
literal|0
index|]
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|rate_tab
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|rate_tab
index|[
literal|0
index|]
argument_list|)
condition|;
name|i
operator|++
control|)
if|if
condition|(
operator|*
name|pcr
operator|>=
name|rate_tab
index|[
name|i
index|]
condition|)
break|break;
if|if
condition|(
name|i
operator|==
sizeof|sizeof
argument_list|(
name|rate_tab
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|rate_tab
index|[
literal|0
index|]
argument_list|)
condition|)
block|{
comment|/* smaller than smallest */
name|i
operator|--
expr_stmt|;
block|}
comment|/* update with the actual value */
operator|*
name|pcr
operator|=
name|rate_tab
index|[
name|i
index|]
expr_stmt|;
return|return
operator|(
operator|(
literal|255
operator|-
name|i
operator|)
operator|<<
literal|16
operator|)
operator||
name|i
return|;
block|}
end_function

begin_comment
comment|/*  * Open a VCC  *   * This function is called via the common driver code after receiving a  * stack *_INIT command.  The common code has already validated most of  * the request so we just need to check a few more Fore-specific details.  * Then we just issue the command to the CP.  Note that we can't wait around  * for the CP to process the command, so we return success for now and abort  * the connection if the command later fails.  *  * Called at splimp.  *  * Arguments:  *	cup	pointer to device common unit  *	cvp	pointer to common VCC entry  *  * Returns:  *	0	open successful  *	else 	open failed  *  */
end_comment

begin_function
name|int
name|fore_openvcc
parameter_list|(
name|cup
parameter_list|,
name|cvp
parameter_list|)
name|Cmn_unit
modifier|*
name|cup
decl_stmt|;
name|Cmn_vcc
modifier|*
name|cvp
decl_stmt|;
block|{
name|Fore_unit
modifier|*
name|fup
init|=
operator|(
name|Fore_unit
operator|*
operator|)
name|cup
decl_stmt|;
name|Fore_vcc
modifier|*
name|fvp
init|=
operator|(
name|Fore_vcc
operator|*
operator|)
name|cvp
decl_stmt|;
name|H_cmd_queue
modifier|*
name|hcp
decl_stmt|;
name|Cmd_queue
modifier|*
name|cqp
decl_stmt|;
name|struct
name|vccb
modifier|*
name|vcp
decl_stmt|;
name|vcp
operator|=
name|fvp
operator|->
name|fv_connvc
operator|->
name|cvc_vcc
expr_stmt|;
name|ATM_DEBUG4
argument_list|(
literal|"fore_openvcc: fup=%p, fvp=%p, vcc=(%d,%d)\n"
argument_list|,
name|fup
argument_list|,
name|fvp
argument_list|,
name|vcp
operator|->
name|vc_vpi
argument_list|,
name|vcp
operator|->
name|vc_vci
argument_list|)
expr_stmt|;
comment|/* 	 * Validate the VPI and VCI values 	 */
if|if
condition|(
operator|(
name|vcp
operator|->
name|vc_vpi
operator|>
name|fup
operator|->
name|fu_pif
operator|.
name|pif_maxvpi
operator|)
operator|||
operator|(
name|vcp
operator|->
name|vc_vci
operator|>
name|fup
operator|->
name|fu_pif
operator|.
name|pif_maxvci
operator|)
condition|)
block|{
return|return
operator|(
literal|1
operator|)
return|;
block|}
comment|/* 	 * Compute the PCR (but only for outgoing VCCs) 	 */
name|fvp
operator|->
name|rate
operator|=
name|FORE_DEF_RATE
expr_stmt|;
if|if
condition|(
operator|(
name|vcp
operator|->
name|vc_type
operator|&
name|VCC_OUT
operator|)
operator|&&
name|cvp
operator|->
name|cv_connvc
condition|)
block|{
name|Atm_attributes
modifier|*
name|attr
init|=
operator|&
name|cvp
operator|->
name|cv_connvc
operator|->
name|cvc_attr
decl_stmt|;
if|if
condition|(
name|attr
operator|&&
name|attr
operator|->
name|traffic
operator|.
name|v
operator|.
name|forward
operator|.
name|PCR_all_traffic
operator|>
literal|0
operator|&&
name|attr
operator|->
name|traffic
operator|.
name|v
operator|.
name|forward
operator|.
name|PCR_all_traffic
operator|<
name|rate_tab
index|[
literal|0
index|]
operator|&&
operator|(
name|fup
operator|->
name|fu_shape
operator|==
name|FUS_SHAPE_ALL
operator|||
operator|(
name|fup
operator|->
name|fu_shape
operator|==
name|FUS_SHAPE_ONE
operator|&&
name|fup
operator|->
name|fu_num_shaped
operator|==
literal|0
operator|)
operator|)
condition|)
block|{
name|fvp
operator|->
name|rate
operator|=
name|pcr2rate
argument_list|(
operator|&
name|attr
operator|->
name|traffic
operator|.
name|v
operator|.
name|forward
operator|.
name|PCR_all_traffic
argument_list|)
expr_stmt|;
name|fup
operator|->
name|fu_num_shaped
operator|++
expr_stmt|;
block|}
block|}
comment|/* 	 * Only need to tell the CP about incoming VCCs 	 */
if|if
condition|(
operator|(
name|vcp
operator|->
name|vc_type
operator|&
name|VCC_IN
operator|)
operator|==
literal|0
condition|)
block|{
name|DEVICE_LOCK
argument_list|(
operator|(
name|Cmn_unit
operator|*
operator|)
name|fup
argument_list|)
expr_stmt|;
name|fup
operator|->
name|fu_open_vcc
operator|++
expr_stmt|;
name|fvp
operator|->
name|fv_state
operator|=
name|CVS_ACTIVE
expr_stmt|;
name|DEVICE_UNLOCK
argument_list|(
operator|(
name|Cmn_unit
operator|*
operator|)
name|fup
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* 	 * Queue command at end of command queue 	 */
name|hcp
operator|=
name|fup
operator|->
name|fu_cmd_tail
expr_stmt|;
if|if
condition|(
operator|(
operator|*
name|hcp
operator|->
name|hcq_status
operator|)
operator|&
name|QSTAT_FREE
condition|)
block|{
comment|/* 		 * Queue entry available, so set our view of things up 		 */
name|hcp
operator|->
name|hcq_code
operator|=
name|CMD_ACT_VCCIN
expr_stmt|;
name|hcp
operator|->
name|hcq_arg
operator|=
name|fvp
expr_stmt|;
name|fup
operator|->
name|fu_cmd_tail
operator|=
name|hcp
operator|->
name|hcq_next
expr_stmt|;
name|fvp
operator|->
name|fv_flags
operator||=
name|FVF_ACTCMD
expr_stmt|;
comment|/* 		 * Now set the CP-resident queue entry - the CP will grab 		 * the command when the op-code is set. 		 */
name|cqp
operator|=
name|hcp
operator|->
name|hcq_cpelem
expr_stmt|;
operator|(
operator|*
name|hcp
operator|->
name|hcq_status
operator|)
operator|=
name|QSTAT_PENDING
expr_stmt|;
name|cqp
operator|->
name|cmdq_act
operator|.
name|act_vccid
operator|=
name|CP_WRITE
argument_list|(
name|vcp
operator|->
name|vc_vci
argument_list|)
expr_stmt|;
if|if
condition|(
name|fvp
operator|->
name|fv_aal
operator|==
name|FORE_AAL_0
condition|)
name|cqp
operator|->
name|cmdq_act
operator|.
name|act_batch
operator|=
name|CP_WRITE
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|cqp
operator|->
name|cmdq_act
operator|.
name|act_spec
operator|=
name|CP_WRITE
argument_list|(
name|ACT_SET_SPEC
argument_list|(
name|BUF_STRAT_1
argument_list|,
name|fvp
operator|->
name|fv_aal
argument_list|,
name|CMD_ACT_VCCIN
operator||
name|CMD_INTR_REQ
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* 		 * Command queue full 		 */
name|fup
operator|->
name|fu_stats
operator|->
name|st_drv
operator|.
name|drv_cm_full
operator|++
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Close a VCC  *   * This function is called via the common driver code after receiving a  * stack *_TERM command.  The common code has already validated most of  * the request so we just need to check a few more Fore-specific details.  * Then we just issue the command to the CP.  Note that we can't wait around  * for the CP to process the command, so we return success for now and whine  * if the command later fails.  *  * Called at splimp.  *  * Arguments:  *	cup	pointer to device common unit  *	cvp	pointer to common VCC entry  *  * Returns:  *	0	close successful  *	else 	close failed  *  */
end_comment

begin_function
name|int
name|fore_closevcc
parameter_list|(
name|cup
parameter_list|,
name|cvp
parameter_list|)
name|Cmn_unit
modifier|*
name|cup
decl_stmt|;
name|Cmn_vcc
modifier|*
name|cvp
decl_stmt|;
block|{
name|Fore_unit
modifier|*
name|fup
init|=
operator|(
name|Fore_unit
operator|*
operator|)
name|cup
decl_stmt|;
name|Fore_vcc
modifier|*
name|fvp
init|=
operator|(
name|Fore_vcc
operator|*
operator|)
name|cvp
decl_stmt|;
name|H_xmit_queue
modifier|*
name|hxp
decl_stmt|;
name|H_cmd_queue
modifier|*
name|hcp
decl_stmt|;
name|Cmd_queue
modifier|*
name|cqp
decl_stmt|;
name|struct
name|vccb
modifier|*
name|vcp
decl_stmt|;
name|int
name|i
decl_stmt|,
name|err
init|=
literal|0
decl_stmt|;
name|vcp
operator|=
name|fvp
operator|->
name|fv_connvc
operator|->
name|cvc_vcc
expr_stmt|;
name|ATM_DEBUG4
argument_list|(
literal|"fore_closevcc: fup=%p, fvp=%p, vcc=(%d,%d)\n"
argument_list|,
name|fup
argument_list|,
name|fvp
argument_list|,
name|vcp
operator|->
name|vc_vpi
argument_list|,
name|vcp
operator|->
name|vc_vci
argument_list|)
expr_stmt|;
name|DEVICE_LOCK
argument_list|(
operator|(
name|Cmn_unit
operator|*
operator|)
name|fup
argument_list|)
expr_stmt|;
comment|/* 	 * Clear any references to this VCC in our transmit queue 	 */
for|for
control|(
name|hxp
operator|=
name|fup
operator|->
name|fu_xmit_head
operator|,
name|i
operator|=
literal|0
init|;
operator|(
operator|*
name|hxp
operator|->
name|hxq_status
operator|!=
name|QSTAT_FREE
operator|)
operator|&&
operator|(
name|i
operator|<
name|XMIT_QUELEN
operator|)
condition|;
name|hxp
operator|=
name|hxp
operator|->
name|hxq_next
operator|,
name|i
operator|++
control|)
block|{
if|if
condition|(
name|hxp
operator|->
name|hxq_vcc
operator|==
name|fvp
condition|)
block|{
name|hxp
operator|->
name|hxq_vcc
operator|=
name|NULL
expr_stmt|;
block|}
block|}
comment|/* 	 * Clear any references to this VCC in our command queue 	 */
for|for
control|(
name|hcp
operator|=
name|fup
operator|->
name|fu_cmd_head
operator|,
name|i
operator|=
literal|0
init|;
operator|(
operator|*
name|hcp
operator|->
name|hcq_status
operator|!=
name|QSTAT_FREE
operator|)
operator|&&
operator|(
name|i
operator|<
name|CMD_QUELEN
operator|)
condition|;
name|hcp
operator|=
name|hcp
operator|->
name|hcq_next
operator|,
name|i
operator|++
control|)
block|{
switch|switch
condition|(
name|hcp
operator|->
name|hcq_code
condition|)
block|{
case|case
name|CMD_ACT_VCCIN
case|:
case|case
name|CMD_ACT_VCCOUT
case|:
if|if
condition|(
name|hcp
operator|->
name|hcq_arg
operator|==
name|fvp
condition|)
block|{
name|hcp
operator|->
name|hcq_arg
operator|=
name|NULL
expr_stmt|;
block|}
break|break;
block|}
block|}
comment|/* 	 * If this VCC has been previously activated, then we need to tell 	 * the CP to deactivate it. 	 */
if|if
condition|(
name|fvp
operator|->
name|fv_flags
operator|&
name|FVF_ACTCMD
condition|)
block|{
comment|/* 		 * Queue command at end of command queue 		 */
name|hcp
operator|=
name|fup
operator|->
name|fu_cmd_tail
expr_stmt|;
if|if
condition|(
operator|(
operator|*
name|hcp
operator|->
name|hcq_status
operator|)
operator|&
name|QSTAT_FREE
condition|)
block|{
comment|/* 			 * Queue entry available, so set our view of things up 			 */
name|hcp
operator|->
name|hcq_code
operator|=
name|CMD_DACT_VCCIN
expr_stmt|;
name|hcp
operator|->
name|hcq_arg
operator|=
name|fvp
expr_stmt|;
name|fup
operator|->
name|fu_cmd_tail
operator|=
name|hcp
operator|->
name|hcq_next
expr_stmt|;
comment|/* 			 * Now set the CP-resident queue entry - the CP will  			 * grab the command when the op-code is set. 			 */
name|cqp
operator|=
name|hcp
operator|->
name|hcq_cpelem
expr_stmt|;
operator|(
operator|*
name|hcp
operator|->
name|hcq_status
operator|)
operator|=
name|QSTAT_PENDING
expr_stmt|;
name|cqp
operator|->
name|cmdq_dact
operator|.
name|dact_vccid
operator|=
name|CP_WRITE
argument_list|(
name|vcp
operator|->
name|vc_vci
argument_list|)
expr_stmt|;
name|cqp
operator|->
name|cmdq_dact
operator|.
name|dact_cmd
operator|=
name|CP_WRITE
argument_list|(
name|CMD_DACT_VCCIN
operator||
name|CMD_INTR_REQ
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* 			 * Command queue full 			 * 			 * If we get here, we'll be getting out-of-sync with 			 * the CP because we can't (for now at least) do 			 * anything about close errors in the common code. 			 * This won't be too bad, since we'll just toss any 			 * PDUs received from the VCC and the sigmgr's will 			 * always get open failures when trying to use this 			 * (vpi,vci)...oh, well...always gotta have that one 			 * last bug to fix! XXX 			 */
name|fup
operator|->
name|fu_stats
operator|->
name|st_drv
operator|.
name|drv_cm_full
operator|++
expr_stmt|;
name|err
operator|=
literal|1
expr_stmt|;
block|}
block|}
comment|/* 	 * Finish up... 	 */
if|if
condition|(
name|fvp
operator|->
name|fv_state
operator|==
name|CVS_ACTIVE
condition|)
name|fup
operator|->
name|fu_open_vcc
operator|--
expr_stmt|;
if|if
condition|(
name|fvp
operator|->
name|rate
operator|!=
literal|0
condition|)
name|fup
operator|->
name|fu_num_shaped
operator|--
expr_stmt|;
name|DEVICE_UNLOCK
argument_list|(
operator|(
name|Cmn_unit
operator|*
operator|)
name|fup
argument_list|)
expr_stmt|;
return|return
operator|(
name|err
operator|)
return|;
block|}
end_function

end_unit

