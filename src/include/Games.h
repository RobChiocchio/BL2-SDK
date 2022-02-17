#pragma once

#include "stdafx.h"
#include <map>
#include "MemorySignature.h"

static std::map<std::string, MemorySignature> bl2_signatures{{
	{
	"GNames", {
		"\x00\x00\x00\x00\x83\x3C\x81\x00\x74\x5C",
		"????xxxxxx",
		10
	}},
	{
	"GObjects", {
		"\x00\x00\x00\x00\x8B\x04\xB1\x8B\x40\x08",
		"????xxxxxx",
		10
	}},
	{
	"SetCommand", {
		"\x83\xC4\x0C\x85\xC0\x75\x1A\x6A\x01\x8D",
		"xxxxxxxxxx",
		10
	}},
	{
	"ProcessEvent", {
		"\x55\x8B\xEC\x6A\xFF\x68\x00\x00\x00\x00\x64\xA1\x00\x00\x00\x00\x50\x83\xEC\x50\xA1\x00\x00\x00\x00\x33\xC5\x89\x45\xF0\x53\x56\x57\x50\x8D\x45\xF4\x64\xA3\x00\x00\x00\x00\x8B\xF1\x89\x75\xEC",
		"xxxxxx????xx????xxxxx????xxxxxxxxxxxxxx????xxxxx",
		48
	}},
	{
	"CallFunction", {
		"\x55\x8B\xEC\x6A\xFF\x68\x00\x00\x00\x00\x64\xA1\x00\x00\x00\x00\x50\x81\xEC\x00\x00\x00\x00\xA1\x00\x00\x00\x00\x33\xC5\x89\x45\xF0\x53\x56\x57\x50\x8D\x45\xF4\x64\xA3\x00\x00\x00\x00\x8B\x7D\x10\x8B\x45\x0C",
		"xxxxxx????xx????xxx????x????xxxxxxxxxxxxxx????xxxxxx",
		52
	}},
	{
	"FrameStep", {
		"\x55\x8B\xEC\x8B\x41\x18\x0F\xB6\x10",
		"xxxxxxxxx",
		9
	}},
	{
	"StaticConstructor", {
		"\x55\x8B\xEC\x6A\xFF\x68\x00\x00\x00\x00\x64\xA1\x00\x00\x00\x00\x50\x83\xEC\x10\x53\x56\x57\xA1\x00\x00\x00\x00\x33\xC5\x50\x8D\x45\xF4\x64\xA3\x00\x00\x00\x00\x8B\x7D\x08\x8A\x87",
		"xxxxxx????xx????xxxxxxxx????xxxxxxxx????xxxxx",
		45
	}},
	{
	"LoadPackage", {
		"\x55\x8B\xEC\x6A\xFF\x68\x00\x00\x00\x00\x64\xA1\x00\x00\x00\x00\x50\x83\xEC\x68\xA1\x00\x00\x00\x00\x33\xC5\x89\x45\xEC",
		"xxxxxx????xx????xxxxx????xxxxx",
		30
	}},
	{
	"GMalloc", {
		"\x00\x00\x00\x00\xFF\xD7\x83\xC4\x04\x89\x45\xE4",
		"????xxxxxxxx",
		12
	}},
	{
	"FNameInit", {
		"\x55\x8B\xEC\x6A\xFF\x68\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x50\x81\xEC\x9C\x0C",
		"xxxxxx??????xxxxxxxxx",
		21
	}},
	{
	"GetDefaultObject", {
		"\x55\x8B\xEC\x56\x8B\xF1\x83\xBE\x00\x01\x00\x00\x00\x57\x0F\x85",
		"xxxxxxxx?xxxxxxx",
		16
	}}
}};

static std::map<std::string, MemorySignature> tps_signatures{ {
	{
	"GNames", {
		"\x00\x00\x00\x00\x8B\x04\xB1\x5E\x5D\xC3\x8B\x15",
		"????xxxxxxxx",
		12
	}},
	{"GObjects", bl2_signatures["GObjects"]},
	{"SetCommand", bl2_signatures["SetCommand"]},
	{"ProcessEvent", bl2_signatures["ProcessEvent"]},
	{"CallFunction", bl2_signatures["CallFunction"]},
	{"FrameStep", bl2_signatures["FrameStep"]},
	{"StaticConstructor", bl2_signatures["StaticConstructor"]},
	{"LoadPackage", bl2_signatures["LoadPackage"]},
	{"GMalloc", bl2_signatures["GMalloc"]},
	{"FNameInit", bl2_signatures["FNameInit"]},
	{"GetDefaultObject", bl2_signatures["GetDefaultObject"]},
}};


static std::map<std::string, std::map<std::string, MemorySignature>> game_signature_map{
	{"Borderlands2", bl2_signatures},
	{"BorderlandsPreSequel", tps_signatures},
	{"TinyTina", tps_signatures}
};

static std::map<std::string, std::string> bl2_object_map{
	{"ConsoleObjectType", "WillowConsole"},
	{"ConsoleObjectName", "Transient.WillowGameEngine_0:WillowGameViewportClient_0.WillowConsole_0"},
	{"EngineObjectType", "WillowGameEngine"},
	{"EngineObjectName", "Transient.WillowGameEngine"},
	{"EngineFullName", "WillowGameEngine Transient.WillowGameEngine"},
	{"PostRenderFunction", "WillowGame.WillowGameViewportClient.PostRender"}
};

static std::map<std::string, std::map<std::string, std::string>> game_object_map{
	{"Borderlands2", bl2_object_map},
	{"BorderlandsPreSequel", bl2_object_map},
	{"TinyTina", bl2_object_map}
};