begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ACTION.H: Symbols for all PCB action codes. */
end_comment

begin_comment
comment|/* CONACT.H: Symbols for content parse action names (end with '_').              There must be no conflict with PARSEACT.H, which              uses 0 through 19, or SGMLACT.H, which uses 20 through 32              (except that 31 - 32 can be defined here because they are              used only by PARSEPRO and do not conflict with SGML.C). */
end_comment

begin_define
define|#
directive|define
name|CIR_
value|31
end_define

begin_comment
comment|/* Invalid character(s) ignored in MDS; restarting parse. */
end_comment

begin_define
define|#
directive|define
name|DTD_
value|32
end_define

begin_comment
comment|/* Process DOCTYPE declaration. */
end_comment

begin_define
define|#
directive|define
name|DTE_
value|33
end_define

begin_comment
comment|/* End of DOCTYPE declaration. */
end_comment

begin_define
define|#
directive|define
name|PEP_
value|34
end_define

begin_comment
comment|/* TEMP: Previous character ended prolog. */
end_comment

begin_define
define|#
directive|define
name|DAS_
value|35
end_define

begin_comment
comment|/* Current character begins data. */
end_comment

begin_define
define|#
directive|define
name|FCE_
value|36
end_define

begin_comment
comment|/* Process free character (SR12-18, 21-30). */
end_comment

begin_define
define|#
directive|define
name|DCE_
value|37
end_define

begin_comment
comment|/* Data character in element text; change PCB. */
end_comment

begin_define
define|#
directive|define
name|LAS_
value|38
end_define

begin_comment
comment|/* Start lookahead buffer with current character. */
end_comment

begin_define
define|#
directive|define
name|LAM_
value|39
end_define

begin_comment
comment|/* Move character to lookahead buffer. */
end_comment

begin_define
define|#
directive|define
name|LAF_
value|40
end_define

begin_comment
comment|/* Flush the lookahead buffer; REPEATCC. */
end_comment

begin_define
define|#
directive|define
name|NED_
value|41
end_define

begin_comment
comment|/* Process null end-tag delimiter. */
end_comment

begin_define
define|#
directive|define
name|NET_
value|42
end_define

begin_comment
comment|/* Process null end-tag. */
end_comment

begin_define
define|#
directive|define
name|NST_
value|43
end_define

begin_comment
comment|/* Process null start-tag. */
end_comment

begin_define
define|#
directive|define
name|NLF_
value|44
end_define

begin_comment
comment|/* Flush lookahead buffer except for trailing NET or SR. */
end_comment

begin_define
define|#
directive|define
name|ETC_
value|45
end_define

begin_comment
comment|/* End-tag in CDATA or RCDATA; treat as data if invalid. */
end_comment

begin_define
define|#
directive|define
name|SRMIN
value|46
end_define

begin_comment
comment|/* Dummy for SHORT REFERENCES: srn = SRn - SRMIN. */
end_comment

begin_define
define|#
directive|define
name|SR1_
value|47
end_define

begin_comment
comment|/* TAB */
end_comment

begin_define
define|#
directive|define
name|SR2_
value|48
end_define

begin_comment
comment|/* RE */
end_comment

begin_define
define|#
directive|define
name|SR3_
value|49
end_define

begin_comment
comment|/* RS */
end_comment

begin_define
define|#
directive|define
name|SR4_
value|50
end_define

begin_comment
comment|/* Leading blanks */
end_comment

begin_define
define|#
directive|define
name|SR5_
value|51
end_define

begin_comment
comment|/* Null record */
end_comment

begin_define
define|#
directive|define
name|DAR_
value|52
end_define

begin_comment
comment|/* Flush data buffer after repeating current character. */
end_comment

begin_define
define|#
directive|define
name|SR7_
value|53
end_define

begin_comment
comment|/* Trailing blanks */
end_comment

begin_define
define|#
directive|define
name|SR8_
value|54
end_define

begin_comment
comment|/* Space */
end_comment

begin_define
define|#
directive|define
name|SR9_
value|55
end_define

begin_comment
comment|/* Two or more blanks */
end_comment

begin_define
define|#
directive|define
name|SR10
value|56
end_define

begin_comment
comment|/* Quotation mark (first data character) */
end_comment

begin_define
define|#
directive|define
name|SR11
value|57
end_define

begin_comment
comment|/* Number sign */
end_comment

begin_define
define|#
directive|define
name|SR12
value|58
end_define

begin_comment
comment|/* FCE CHARACTERS start here */
end_comment

begin_comment
comment|/*         _   59   */
end_comment

begin_define
define|#
directive|define
name|BSQ_
value|60
end_define

begin_comment
comment|/* Blank sequence begun; find its end. */
end_comment

begin_comment
comment|/*             61      In use by PARSEACT.H */
end_comment

begin_comment
comment|/*             62      In use by PARSEACT.H */
end_comment

begin_comment
comment|/*             63      In use by PARSEACT.H */
end_comment

begin_comment
comment|/*             64      In use by PARSEACT.H */
end_comment

begin_define
define|#
directive|define
name|SR19
value|65
end_define

begin_comment
comment|/* Hyphen */
end_comment

begin_define
define|#
directive|define
name|SR20
value|66
end_define

begin_comment
comment|/* Two hyphens */
end_comment

begin_define
define|#
directive|define
name|SR25
value|71
end_define

begin_comment
comment|/* Left bracket */
end_comment

begin_define
define|#
directive|define
name|SR26
value|72
end_define

begin_comment
comment|/* Right bracket */
end_comment

begin_define
define|#
directive|define
name|RBR_
value|73
end_define

begin_comment
comment|/* Two right brackets. */
end_comment

begin_define
define|#
directive|define
name|GTR_
value|74
end_define

begin_comment
comment|/* EOB with pending data character */
end_comment

begin_define
define|#
directive|define
name|MSP_
value|75
end_define

begin_comment
comment|/* Marked section start in prolog outside DTD */
end_comment

begin_define
define|#
directive|define
name|APP_
value|76
end_define

begin_comment
comment|/* APPINFO (other than NONE) */
end_comment

begin_define
define|#
directive|define
name|STE_
value|77
end_define

begin_comment
comment|/* Start tag ended prolog */
end_comment

begin_define
define|#
directive|define
name|ETE_
value|78
end_define

begin_comment
comment|/* End tag ended prolog */
end_comment

begin_comment
comment|/* GRPACT.H: Symbols for group tokenization action names (all alpha).              There must be no conflict with PARSEACT.H, which              uses 0 - 19. */
end_comment

begin_define
define|#
directive|define
name|AND
value|20
end_define

begin_comment
comment|/* AND connector found. */
end_comment

begin_define
define|#
directive|define
name|DTAG
value|21
end_define

begin_comment
comment|/* Data tag token group occurred (treat as #CHARS). */
end_comment

begin_define
define|#
directive|define
name|GRPE
value|22
end_define

begin_comment
comment|/* Group ended. */
end_comment

begin_define
define|#
directive|define
name|GRP_
value|23
end_define

begin_comment
comment|/* Group started. */
end_comment

begin_define
define|#
directive|define
name|NAS_
value|24
end_define

begin_comment
comment|/* Name started in content model or name group. */
end_comment

begin_define
define|#
directive|define
name|NMT_
value|25
end_define

begin_comment
comment|/* Name or name token started in name token group. */
end_comment

begin_define
define|#
directive|define
name|OPT
value|26
end_define

begin_comment
comment|/* OPT occurrence indicator for previous token. */
end_comment

begin_define
define|#
directive|define
name|OR
value|27
end_define

begin_comment
comment|/* OR connector found. */
end_comment

begin_define
define|#
directive|define
name|OREP
value|28
end_define

begin_comment
comment|/* OREP occurrence indicator for previous token. */
end_comment

begin_define
define|#
directive|define
name|REP
value|29
end_define

begin_comment
comment|/* REP occurrence indicator for previous token. */
end_comment

begin_define
define|#
directive|define
name|RNS_
value|30
end_define

begin_comment
comment|/* Reserved name started (#PCDATA). */
end_comment

begin_define
define|#
directive|define
name|SEQ
value|31
end_define

begin_comment
comment|/* SEQ connector found. */
end_comment

begin_comment
comment|/* LITACT.H: Symbols for content parse action names (end with '_').              There must be no conflict with PARSEACT.H, which              uses 0 through 19. */
end_comment

begin_define
define|#
directive|define
name|MLA_
value|20
end_define

begin_comment
comment|/* Move character to look-aside data buffer. */
end_comment

begin_define
define|#
directive|define
name|LPR_
value|21
end_define

begin_comment
comment|/* Move previous character to data buffer. */
end_comment

begin_define
define|#
directive|define
name|RSM_
value|22
end_define

begin_comment
comment|/* Process record start and move it to data buffer. */
end_comment

begin_define
define|#
directive|define
name|FUN_
value|23
end_define

begin_comment
comment|/* Replace function character with a space. */
end_comment

begin_define
define|#
directive|define
name|LP2_
value|24
end_define

begin_comment
comment|/* Move previous two characters to data buffer. */
end_comment

begin_define
define|#
directive|define
name|MLE_
value|25
end_define

begin_comment
comment|/* Minimum literal error: invalid character ignored. */
end_comment

begin_define
define|#
directive|define
name|RPR_
value|26
end_define

begin_comment
comment|/* Remove previous character from data buffer; terminate. */
end_comment

begin_define
define|#
directive|define
name|TER_
value|27
end_define

begin_comment
comment|/* Terminate the parse. */
end_comment

begin_comment
comment|/* MDACT.H: Symbols for markup declaration parse action names (all alpha).             There must be no conflict with PARSEACT.H, which             uses 0 - 19. */
end_comment

begin_define
define|#
directive|define
name|CDR
value|20
end_define

begin_comment
comment|/* CD[1] (MINUS) occurred previously. */
end_comment

begin_define
define|#
directive|define
name|EMD
value|21
end_define

begin_comment
comment|/* End of markup declaration. */
end_comment

begin_define
define|#
directive|define
name|GRPS
value|22
end_define

begin_comment
comment|/* Group started. */
end_comment

begin_define
define|#
directive|define
name|LIT
value|23
end_define

begin_comment
comment|/* Literal started: character data. */
end_comment

begin_define
define|#
directive|define
name|LITE
value|24
end_define

begin_comment
comment|/* Literal started: character data; LITA is delimiter. */
end_comment

begin_define
define|#
directive|define
name|MGRP
value|25
end_define

begin_comment
comment|/* Minus exception group (MINUS,GRPO). */
end_comment

begin_define
define|#
directive|define
name|NAS
value|26
end_define

begin_comment
comment|/* Name started. */
end_comment

begin_define
define|#
directive|define
name|NMT
value|27
end_define

begin_comment
comment|/* Name token started. */
end_comment

begin_define
define|#
directive|define
name|NUM
value|28
end_define

begin_comment
comment|/* Number or number token started. */
end_comment

begin_define
define|#
directive|define
name|PEN
value|29
end_define

begin_comment
comment|/* Parameter entity name being defined (PERO found). */
end_comment

begin_define
define|#
directive|define
name|PGRP
value|30
end_define

begin_comment
comment|/* Plus exception group (PLUS,GRPO). */
end_comment

begin_define
define|#
directive|define
name|RNS
value|31
end_define

begin_comment
comment|/* Reserved name started. */
end_comment

begin_define
define|#
directive|define
name|MDS
value|32
end_define

begin_comment
comment|/* Markup declaration subset start. */
end_comment

begin_define
define|#
directive|define
name|PENR
value|33
end_define

begin_comment
comment|/* REPEATCC; PERO found. */
end_comment

begin_comment
comment|/* PARSEACT.H: Symbols for common parse action names (end with '_').                There must be no conflict with other action name                files, which use numbers greater than 19. */
end_comment

begin_define
define|#
directive|define
name|CRA_
value|1
end_define

begin_comment
comment|/* Character reference: alphabetic. */
end_comment

begin_define
define|#
directive|define
name|CRN_
value|2
end_define

begin_comment
comment|/* Character reference: numeric; non-char refs o.k.. */
end_comment

begin_define
define|#
directive|define
name|NON_
value|3
end_define

begin_comment
comment|/* Single byte of non-character data found. */
end_comment

begin_define
define|#
directive|define
name|EOF_
value|4
end_define

begin_comment
comment|/* Error: illegal entity end; resume old input; return. */
end_comment

begin_define
define|#
directive|define
name|ER_
value|5
end_define

begin_comment
comment|/* Entity reference; start new input source; continue. */
end_comment

begin_define
define|#
directive|define
name|GET_
value|6
end_define

begin_comment
comment|/* EOB, EOS, or EE: resume old input source; continue. */
end_comment

begin_define
define|#
directive|define
name|INV_
value|7
end_define

begin_comment
comment|/* Error: invalid char terminated markup; repeat char. */
end_comment

begin_define
define|#
directive|define
name|LEN_
value|8
end_define

begin_comment
comment|/* Error: length limit exceeded; end markup; repeat char. */
end_comment

begin_define
define|#
directive|define
name|NOP_
value|9
end_define

begin_comment
comment|/* No action necessary. */
end_comment

begin_define
define|#
directive|define
name|PCI_
value|10
end_define

begin_comment
comment|/* Previous character was invalid. */
end_comment

begin_define
define|#
directive|define
name|PER_
value|11
end_define

begin_comment
comment|/* Parameter reference; start new input source; continue. */
end_comment

begin_define
define|#
directive|define
name|RC2_
value|12
end_define

begin_comment
comment|/* Back up two characters. */
end_comment

begin_define
define|#
directive|define
name|RCC_
value|13
end_define

begin_comment
comment|/* Repeat current character. */
end_comment

begin_define
define|#
directive|define
name|RCR_
value|14
end_define

begin_comment
comment|/* Repeat current character and return to caller. */
end_comment

begin_define
define|#
directive|define
name|EE_
value|15
end_define

begin_comment
comment|/* EOS or EE: resume old input source; return to caller. */
end_comment

begin_define
define|#
directive|define
name|RS_
value|16
end_define

begin_comment
comment|/* Record start: ccnt=0; ++rcnt. */
end_comment

begin_define
define|#
directive|define
name|ERX_
value|17
end_define

begin_comment
comment|/* Entity reference; start new input source; return. */
end_comment

begin_define
define|#
directive|define
name|SYS_
value|18
end_define

begin_comment
comment|/* Error allowed: SYSCHAR in input stream; replace it. */
end_comment

begin_define
define|#
directive|define
name|EOD_
value|19
end_define

begin_comment
comment|/* End of document. */
end_comment

begin_comment
comment|/* Number way out of order to avoid recompilation. */
end_comment

begin_define
define|#
directive|define
name|NSC_
value|58
end_define

begin_comment
comment|/* Handle DELNONCH/DELXNONCH when NON_ is allowed */
end_comment

begin_define
define|#
directive|define
name|PEX_
value|61
end_define

begin_comment
comment|/* Parameter entity ref; start new input source; return. */
end_comment

begin_define
define|#
directive|define
name|DEF_
value|62
end_define

begin_comment
comment|/* Data entity found. */
end_comment

begin_define
define|#
directive|define
name|PIE_
value|63
end_define

begin_comment
comment|/* PI entity found (needed in markup). */
end_comment

begin_define
define|#
directive|define
name|LNR_
value|64
end_define

begin_comment
comment|/* LEN_ error with extra REPEATCC. */
end_comment

begin_comment
comment|/* SGMLACT.H: Symbols for content parse action names (end with '_')               that are returned to SGML.C for processing.               There must be no conflict with PARSEACT.H, which               uses 0 through 19, or CONACT.H, which uses 34 and above.               (Note: 31 is also used in CONACT.H, but no conflict               is created because they are tested only in PARSEPRO.C, which               completes before SGML.C starts to examine those codes.               Also, when EOD_ is returned from PARSECON, it is changed               to LOP_.) */
end_comment

begin_define
define|#
directive|define
name|CON_
value|20
end_define

begin_comment
comment|/* Normal content action (one of the following). */
end_comment

begin_define
define|#
directive|define
name|DAF_
value|21
end_define

begin_comment
comment|/* Data found. */
end_comment

begin_define
define|#
directive|define
name|ETG_
value|22
end_define

begin_comment
comment|/* Process end-tag. */
end_comment

begin_define
define|#
directive|define
name|MD_
value|23
end_define

begin_comment
comment|/* Process markup declaration (NAMESTRT found). */
end_comment

begin_define
define|#
directive|define
name|MDC_
value|24
end_define

begin_comment
comment|/* Process markup declaration comment (CD found). */
end_comment

begin_define
define|#
directive|define
name|MSS_
value|25
end_define

begin_comment
comment|/* Process marked section start. */
end_comment

begin_define
define|#
directive|define
name|MSE_
value|26
end_define

begin_comment
comment|/* Process marked section end. */
end_comment

begin_define
define|#
directive|define
name|PIS_
value|27
end_define

begin_comment
comment|/* Processing instruction (string). */
end_comment

begin_define
define|#
directive|define
name|REF_
value|28
end_define

begin_comment
comment|/* Record end found. */
end_comment

begin_define
define|#
directive|define
name|STG_
value|29
end_define

begin_comment
comment|/* Process start-tag. */
end_comment

begin_define
define|#
directive|define
name|RSR_
value|30
end_define

begin_comment
comment|/* Return RS to effect SGML state transition. */
end_comment

begin_define
define|#
directive|define
name|LOP_
value|31
end_define

begin_comment
comment|/* Loop for new content without returning anything. */
end_comment

begin_comment
comment|/* TAGACT.H: Symbols for tag parse action names (all alpha).              There must be no conflict with PARSEACT.H, which              uses 0 - 19. */
end_comment

begin_define
define|#
directive|define
name|AVD
value|20
end_define

begin_comment
comment|/* Delimited attribute value started: normal delimiter. */
end_comment

begin_define
define|#
directive|define
name|AVU
value|21
end_define

begin_comment
comment|/* Undelimited value started. */
end_comment

begin_define
define|#
directive|define
name|ETIC
value|22
end_define

begin_comment
comment|/* Tag closed with ETI. */
end_comment

begin_define
define|#
directive|define
name|NVS
value|23
end_define

begin_comment
comment|/* Name of attribute or value started. */
end_comment

begin_define
define|#
directive|define
name|NASV
value|24
end_define

begin_comment
comment|/* Saved NAS was actually an NTV. */
end_comment

begin_define
define|#
directive|define
name|NTV
value|25
end_define

begin_comment
comment|/* Name token value started; get name and full value. */
end_comment

begin_define
define|#
directive|define
name|TAGC
value|26
end_define

begin_comment
comment|/* Tag closed normally. */
end_comment

begin_define
define|#
directive|define
name|TAGO
value|27
end_define

begin_comment
comment|/* Tag closed implicitly by TAGO character. */
end_comment

begin_define
define|#
directive|define
name|AVDA
value|28
end_define

begin_comment
comment|/* Delimited attribute value started: alternative delim. */
end_comment

begin_define
define|#
directive|define
name|DSC
value|29
end_define

begin_comment
comment|/* Closed by DSC character. */
end_comment

begin_comment
comment|/* VALACT.H: Symbols for attribute value tokenization action names (all alpha). */
end_comment

begin_define
define|#
directive|define
name|NOPA
value|0
end_define

begin_comment
comment|/* No action necessary. */
end_comment

begin_define
define|#
directive|define
name|INVA
value|1
end_define

begin_comment
comment|/* Invalid character; terminate parse. */
end_comment

begin_define
define|#
directive|define
name|LENA
value|2
end_define

begin_comment
comment|/* Length limit of token exceeded; terminate parse. */
end_comment

begin_define
define|#
directive|define
name|NASA
value|3
end_define

begin_comment
comment|/* Name started. */
end_comment

begin_define
define|#
directive|define
name|NMTA
value|4
end_define

begin_comment
comment|/* Name token started. */
end_comment

begin_define
define|#
directive|define
name|NUMA
value|5
end_define

begin_comment
comment|/* Number or number token started. */
end_comment

begin_comment
comment|/* SGML declaration parsing actions. */
end_comment

begin_define
define|#
directive|define
name|ESGD
value|20
end_define

begin_comment
comment|/* End of SGML declaration. */
end_comment

begin_define
define|#
directive|define
name|LIT1
value|21
end_define

begin_comment
comment|/* Literal started. */
end_comment

begin_define
define|#
directive|define
name|LIT2
value|22
end_define

begin_comment
comment|/* Literal started with LITA delimiter. */
end_comment

begin_define
define|#
directive|define
name|NUM1
value|23
end_define

begin_comment
comment|/* Number started. */
end_comment

begin_define
define|#
directive|define
name|NAS1
value|24
end_define

begin_comment
comment|/* Name started. */
end_comment

begin_define
define|#
directive|define
name|ISIG
value|25
end_define

begin_comment
comment|/* Insignificant character occurred. */
end_comment

end_unit

