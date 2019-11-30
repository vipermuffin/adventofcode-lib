//
//  Advent of Code Utilities: Generic Linear Traveler
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin 
//  Copyright © 2018 vipermuffin. All rights reserved.
//
#pragma once
#include <string>

namespace AocUtils {
//Function Definitions
    template<typename T>
    class LinearTraveler {
    public:
        LinearTraveler(const std::string& id,
                       const T timestepsize,
                       const T accel,
                       const T velocity,
                       const T position,
                       const T onTime,
                       const T offTime);
        LinearTraveler();
        ~LinearTraveler(){}
        void setTimestep(const T);
        void setAccelerationPerTimestep(const T);
        void setVelocityPerTimeStep(const T);
        void setPosition(const T);
        void setName(const std::string&);
        void setOnTimeInSteps(const T);
        void setOffTimeInSteps(const T);
        void step();
        void step(T);
        void reset();
        T position() const;
        T currentTimeStep() const;
        std::string name() const;
        
    private:
        std::string _name;
        T _timeStepSize;
        T _acceleration;
        T _velocity;
        T _position;
        T _onTimeInSteps;
        T _offTimeInSteps;
        T _currentTimeStep;
        T _OnTimerInSteps;
        T _OffTimerInSteps;
    };
    
    template<typename T>
    LinearTraveler<T>::LinearTraveler(const std::string& id,
                                   const T timestepsize,
                                   const T accel,
                                   const T velocity,
                                   const T position,
                                   const T onTime,
                                   const T offTime) :
    _name{id},
    _timeStepSize{timestepsize},
    _acceleration{accel},
    _velocity{velocity},
    _position{position},
    _onTimeInSteps{onTime},
    _offTimeInSteps{offTime},
    _currentTimeStep{0},
    _OnTimerInSteps{0},
    _OffTimerInSteps{0}
    {}
    
    template<typename T>
    LinearTraveler<T>::LinearTraveler() :
    _name{"NULL_ID"},
    _timeStepSize{0},
    _acceleration{0},
    _velocity{0},
    _position{0},
    _onTimeInSteps{0},
    _offTimeInSteps{0},
    _currentTimeStep{0},
    _OnTimerInSteps{0},
    _OffTimerInSteps{0}
    {}
    
    template<typename T>
    void LinearTraveler<T>::setTimestep(const T timestepsize) {
        _timeStepSize = timestepsize;
    }
    
    template<typename T>
    void LinearTraveler<T>::setAccelerationPerTimestep(const T accel) {
        _acceleration = accel;
    }
    
    template<typename T>
    void LinearTraveler<T>::setVelocityPerTimeStep(const T v) {
        _velocity = v;
    }
    
    template<typename T>
    void LinearTraveler<T>::setPosition(const T pos) {
        _position = pos;
    }
    
    template<typename T>
    void LinearTraveler<T>::setName(const std::string& name) {
        _name = name;
    }
    
    template<typename T>
    void LinearTraveler<T>::setOnTimeInSteps(const T onTimeInSteps) {
        _onTimeInSteps = onTimeInSteps;
    }
    
    template<typename T>
    void LinearTraveler<T>::setOffTimeInSteps(const T offTimeInSteps) {
        _offTimeInSteps = offTimeInSteps;
    }
    
    template<typename T>
    void LinearTraveler<T>::step() {
        if(_offTimeInSteps != 0) {
            if(_OnTimerInSteps < _onTimeInSteps) {
                _OnTimerInSteps += _timeStepSize;
                _velocity += _acceleration;
                _position += _velocity;
            } else if(_OffTimerInSteps < _offTimeInSteps) {
                _OffTimerInSteps += _timeStepSize;
            } else {
                _OffTimerInSteps = 0;
                _OnTimerInSteps = _timeStepSize;
                _velocity += _acceleration;
                _position += _velocity;
            }
        } else {
            _velocity += _acceleration;
            _position += _velocity;
        }

        _currentTimeStep += _timeStepSize;
    }
    
    template<typename T>
    void LinearTraveler<T>::step(T time) {
        for(T i = 0; i < time; i += _timeStepSize) {
            this->step();
        }
    }
    
    template<typename T>
    T LinearTraveler<T>::position() const {
        return _position;
    }
    
    template<typename T>
    T LinearTraveler<T>::currentTimeStep() const {
        return _currentTimeStep;
    }
    
    template<typename T>
    std::string LinearTraveler<T>::name() const {
        return _name;
    }
    
    template<typename T>
    void LinearTraveler<T>::reset() {
        _position = 0;
        _currentTimeStep = 0;
        _OnTimerInSteps = 0;
        _OffTimerInSteps = 0;
    }
}
