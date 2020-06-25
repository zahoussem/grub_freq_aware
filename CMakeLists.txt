cmake_minimum_required(VERSION 3.10.2)
project(sched_sim)

cmake_minimum_required(VERSION 2.8)

file(GLOB helloworld_SRC
  "common/*.hpp"
  "common/*.cpp"
  "platform/*.hpp"
  "platform/*.cpp"
  "resa_res/*.hpp"
  "resa_res/*.cpp"
  "sched/*.hpp"
  "sched/*.cpp"
  "sim_engine/*.hpp"
  "sim_engine/*.cpp"
  "task/*.hpp"
  "task/*.cpp"
  "*.hpp"
  "*.cpp"
  )

add_executable(testing ${helloworld_SRC})
