import java.util.*;

public class CircularLinkedList{

    class Node {
        Object data;
        Node next;
        
        Node(Object newData, Node next) {
            this.data = newData;
            this.next = next;
        } 

    }
    
    private Node head, tail;
    private int size = 0;
    
    public boolean isEmpty() {
        return size == 0;
    }
    
    public int search(Object data) {
        int index = 0;
        if (!isEmpty()) {
            Node temp = head;
            while(temp.data != data ) {
                index++;
                temp = temp.next;
                if(temp == null) {
                    return -1;
                }
            }
            return index;
        } else {
            return -5;
        }
    }

    public void addFirst(Object newData) {
        Node newest = new Node(newData, null);
        if(isEmpty()) {
            head = newest;
            tail = newest;
            tail.next = head;
        } else {
            tail.next = newest;
            newest.next = head;
            head = newest;
        }
        size++;
    }

    public void addLast(Object newData) {
        if(isEmpty()) {
            addFirst(newData);
        } else {
            Node newest = new Node(newData, head);
            tail.next = newest;
            tail = newest;
        }
        size++;
    }

    public void addAt(Object newData, int index) {
        if(!isEmpty()) {
            Node previous = head;
            for(int j = 0; j < index-1; j++) {
                previous = previous.next;
            }
            Node after = previous.next;
            Node newest = new Node(newData, after);
            previous.next = newest;
        } else {
            addFirst(newData);
        }
    }

    public Object removeFirst() {
        if(isEmpty()) return null;
        
        Object removed = head.data;
        tail.next = head.next;
        head = head.next;
        
        size--;
        return removed;
        
    }

    public Object removeLast() {
        int count = 0;
        Node pointer = head;
        Object removed = tail.data;
        
        while(pointer != null) {
            if(count == size-2) {
                tail = pointer;
                tail.next = head;
                break;
            }
            count++;
            pointer = pointer.next;
        }
        size--;
        return removed;
    }
    
    public Object removeAt(int index) {
        Node removed = new Node("List Empty", null);
        if(!isEmpty()) {
            Node prev = head;
            for(int j =0; j < index-1; j++) {
                prev = prev.next;       
            }
            removed = prev.next;
            Node after = removed.next;
            prev.next = after;
        }
        return removed.data;
    }

    public void rotate() {
        if(!isEmpty())
            head = head.next;
    }

    public int size() {
        return size;
    }

    public void print() {
        Node pointer = head;
    
        for(int i = 0; i < size(); i++ ) {
            System.out.print(pointer.data + " -> ");
            pointer = pointer.next;
        }
        
    }
}
