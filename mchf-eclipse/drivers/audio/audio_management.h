/*  -*-  mode: c; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4; coding: utf-8  -*-  */
/************************************************************************************
**                                                                                 **
**                               mcHF QRP Transceiver                              **
**                             K Atanassov - M0NKA 2014                            **
**                                                                                 **
**---------------------------------------------------------------------------------**
**                                                                                 **
**  File name:                                                                     **
**  Description:                                                                   **
**  Last Modified:                                                                 **
**  Licence:        CC BY-NC-SA 3.0                                                **
************************************************************************************/

#ifndef DRIVERS_AUDIO_AUDIO_MANAGEMENT_H_
#define DRIVERS_AUDIO_AUDIO_MANAGEMENT_H_

#include "mchf_types.h"

void    AudioManagement_CalcIqPhaseGainAdjust(float32_t freq);

void    AudioManagement_CalcTxCompLevel(void);
void    AudioManagement_CalcNB_AGC(void);
void    AudioManagement_CalcAGCVals(void);
void    AudioManagement_CalcRFGain(void);
void    AudioManagement_CalcALCDecay(void);
void    AudioManagement_CalcAGCDecay(void);
void    AudioManagement_SetSidetoneForDemodMode(uint16_t dmod_mode, bool tune_mode);

void    AudioManagement_LoadToneBurstMode(void);
void    AudioManagement_CalcSubaudibleGenFreq(void);        // load/set current FM subaudible tone settings for generation
void    AudioManagement_CalcSubaudibleDetFreq();
void    AudioManagement_KeyBeep(void);
void    AudioManagement_LoadBeepFreq(void);



#endif /* DRIVERS_AUDIO_AUDIO_MANAGEMENT_H_ */
