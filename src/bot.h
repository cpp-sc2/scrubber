// The MIT License (MIT)
//
// Copyright (c) 2022 Alexander Kurbatov

#pragma once

#include <sc2api/sc2_agent.h>

struct Bot: sc2::Agent
{
  void OnGameStart() final;

  void OnStep() final;
};
