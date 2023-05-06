#pragma once

char ContentPath[256];
char RelativePath[256];

void SoundInit();
void SoundExit();

void SoundPlaySound(int soundNumber);
void SoundPlayEffect(int soundNumber);
void SoundStopSound();

void LoopSound(int soundNumber);