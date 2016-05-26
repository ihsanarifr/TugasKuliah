import angular from 'angular';
import angularMeteor from 'angular-meteor';
import { Tasks } from '../../api/tasks.js';
import { Meteor } from 'meteor/meteor';

import template from './todosList.html';

// class TodosListCtrl {
//   constructor() {
//     this.tasks = [{
//       text: 'This is task 1'
//     }, {
//       text: 'This is task 2'
//     }, {
//       text: 'This is task 3'
//     }];
//   }
// }
class TodosListCtrl{
  constructor($scope){
    $scope.viewModel(this);

    // sama kyk load model di mongodb
    this.subscribe('tasks');

    this.hideCompleted = false;

    this.helpers({
      tasks(){
        const selector = {};

        // if hide complete is checked, filter task
        if (this.getReactively('hideCompleted')) {
          selector.checked = {
            $ne: true
          };
        }

        // show newest tasks at the top
        return Tasks.find({
          checked:{
            $ne:true
          }
        },{
          sort:{
            createdAt: -1
          }
        });
      },
      incompleteCount(){
        return Tasks.find({
          checked:{
            $ne:true
          }
        }).count();
      },
      currentUser(){
        return Meteor.user();
      }
    })
  }
  
  addTask(newTask){
    // insdrt a task into the collection
    // Tasks.insert({
    //   text: newTask,
    //   createdAt: new Date,
    //   owner: Meteor.userId(),
    //   username: Meteor.user().username
    // });

    // insert using api meteor
    Meteor.call('task.insert',newTask);

    // clear form
    this.newTask='';
  }

  setChecked(task){
    // set the cheked property to the opposite of its current value
    // Tasks.update(task._id,{
    //   $set:{
    //     checked: !task.checked
    //   },
    // });

    // set using api task
    Meteor.call('task.setChecked',task._id,!task.checked);
  }

  removeTask(task){
    // Tasks.remove(task._id);

    // delete using api meteor
    Meteor.call('tasks.remove',task._id);
  }

  setPrivate(task){
    Meteor,call('tasks.setPrivate',task._id,!task.private);
  }
}

export default angular.module('todosList', [
  angularMeteor
])
  .component('todosList', {
    templateUrl: 'imports/components/todosList/todosList.html',
    controller: ['$scope',TodosListCtrl]
  });
